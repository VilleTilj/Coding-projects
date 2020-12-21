const responseUtils = require('./utils/responseUtils');
const { acceptsJson, parseBodyJson } = require('./utils/requestUtils');
const { renderPublic } = require('./utils/render');
const { basicAuthChallenge,unauthorized, badRequest, forbidden} = require('./utils/responseUtils');
const { getCurrentUser } = require('./auth/auth');
const {getAllProducts } = require('./controllers/products.js');
const getUser = require('./models/user');
const { getAllUsers, registerUser, deleteUser, viewUser, updateUser } = require('./controllers/users');
/**
 * Known API routes and their allowed methods
 *
 * Used to check allowed methods and also to send correct header value
 * in response to an OPTIONS request by sendOptions() (Access-Control-Allow-Methods)
 */
const allowedMethods = {
  '/api/register': ['POST'],
  '/api/users': ['GET'],
  '/api/products': ['GET']
};

/**
 * Send response to client options request.
 *
 * @param {string} filePath pathname of the request URL
 * @param {http.ServerResponse} response
 */
const sendOptions = (filePath, response) => {
  if (filePath in allowedMethods) {
    response.writeHead(204, {
      'Access-Control-Allow-Methods': allowedMethods[filePath].join(','),
      'Access-Control-Allow-Headers': 'Content-Type,Accept',
      'Access-Control-Max-Age': '86400',
      'Access-Control-Expose-Headers': 'Content-Type,Accept'
    });
    return response.end();
  }

  return responseUtils.notFound(response);
};

/**
 * Does the url have an ID component as its last part? (e.g. /api/users/dsf7844e)
 *
 * @param {string} url filePath
 * @param {string} prefix
 * @returns {boolean}
 */
const matchIdRoute = (url, prefix) => {
  const idPattern = '[0-9a-z]{8,24}';
  const regex = new RegExp(`^(/api)?/${prefix}/${idPattern}$`);
  return regex.test(url);
};

/**
 * Does the URL match /api/users/{id}
 *
 * @param {string} url filePath
 * @returns {boolean}
 */
const matchUserId = url => {
  return matchIdRoute(url, 'users');
};

const handleRequest = async (request, response) => {
  const { url, method, headers } = request;
  const filePath = new URL(url, `http://${headers.host}`).pathname;

  // serve static files from public/ and return immediately
  if (method.toUpperCase() === 'GET' && !filePath.startsWith('/api')) {
    const fileName = filePath === '/' || filePath === '' ? 'index.html' : filePath;
    return renderPublic(fileName, response);
  }

  if (matchUserId(filePath)) {
    // TODO: 8.5 Implement view, update and delete a single user by ID (GET, PUT, DELETE)
    // You can use parseBodyJson(request) from utils/requestUtils.js to parse request body
    //throw new Error('Not Implemented');
    // Check for authorization
    if ( request.headers['authorization']) {
      const user = await getCurrentUser(request);
      if (user){ 
        const reqUser = await getUser.findById(request.url.split('/')[3]).exec();
        if ( method.toUpperCase() === 'GET') { 
          return viewUser(response, reqUser, user);
        }
          if ( method.toUpperCase() === 'PUT') { 
            const updateRequest = await parseBodyJson(request);
            return updateUser(response, reqUser.id, user, updateRequest);
          }
          if (method.toUpperCase() === 'DELETE') {
            return deleteUser(response, reqUser.id, user);
          }
      } else {
        return basicAuthChallenge(response);
      }
     } else {
      unauthorized(response);
    }
  }


  // Default to 404 Not Found if unknown url
  if (!(filePath in allowedMethods)) return responseUtils.notFound(response);

  // See: http://restcookbook.com/HTTP%20Methods/options/
  if (method.toUpperCase() === 'OPTIONS') return sendOptions(filePath, response);

  // Check for allowable methods
  if (!allowedMethods[filePath].includes(method.toUpperCase())) {
    return responseUtils.methodNotAllowed(response);
  }

  // Require a correct accept header (require 'application/json' or '*/*')
  if (!acceptsJson(request)) {
    return responseUtils.contentTypeNotAcceptable(response);
  }
  const user = await getCurrentUser(request);
  
  if (!user) {
    basicAuthChallenge(response);
  } else {

    // GET all users
    if (filePath === '/api/users' && method.toUpperCase() === 'GET') {
      // DONE: 8.3 Return all users as JSON
      // TODO: 8.4 Add authentication (only allowed to users with role "admin")
        if (user.role === 'admin'){
          return getAllUsers(response);
        }else {
          return forbidden(response);
        }}

    // register new user
    if (filePath === '/api/register' && method.toUpperCase() === 'POST') {
      const isJSON = request => {
        try {
          JSON.parse(request);
      } catch (e) {
          return false;
      }
      return true;
      }; 
      if (!isJSON ) {
        return badRequest(response, 'Invalid Content-Type. Expected application/json');
      }

      // Check for email
      if (!user.email){
        return badRequest(response, '400 Bad Request');
      }

      const updateRequest = await parseBodyJson(request);
      return registerUser(response, updateRequest);
    }
    
    // And products
    if (filePath === '/api/products' && method.toUpperCase() === 'GET') {  
      if (user.role === "admin" || user.role === "customer") {
        return getAllProducts(response);
      } else {
        return forbidden(response);
      }     
    }


    }
};



module.exports = { handleRequest };
