const responseUtils = require('./utils/responseUtils');
const { acceptsJson, isJson, parseBodyJson } = require('./utils/requestUtils');
const { renderPublic } = require('./utils/render');
const { emailInUse, getAllUsers, saveNewUser, validateUser, updateUserRole, getUserById } = require('./utils/users');
const {users, deleteUserById, requestedUsername} = require('./utils/users');
const { basicAuthChallenge, notFound, sendJson, badRequest, unauthorized} = require('./utils/responseUtils');
const { getCurrentUser } = require('./auth/auth');
const productdata = require('./products.json').map(function(product){({ ...product })});
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
        if( user.role === 'admin'){
          const reqName = filePath.split('/').pop();
          const reqUser = getUserById(reqName);
          if (reqUser){  
            if ( request.method === 'GET') { 
              return responseUtils.sendJson(response, reqUser);
            }
            if ( request.method === 'PUT') { 
              const updateRequest = await parseBodyJson(request);
              // if role can be found
              if (updateRequest.role) {
                try {
                  
                  const updatedUser = updateUserRole(requestedUsername, updateRequest.role);
                  return responseUtils.sendJson(response, updatedUser);
                }
                catch (err) { badRequest(response, err);}
              } else { return responseUtils.badRequest(response);}
            }
            if (request.method === 'DELETE') {
              // try to delete user
              const deleted = deleteUserById(requestedUsername);
              if (deleted) {
                return responseUtils.sendJson(response, deleted);
              }
            }} else {
              unauthorized(response);
            }
        } else {return responseUtils.forbidden(response); }
      } else {
        return basicAuthChallenge(response);
      }
    }else {
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

  // GET all users
  if (filePath === '/api/users' && method.toUpperCase() === 'GET') {
    // DONE: 8.3 Return all users as JSON
    // TODO: 8.4 Add authentication (only allowed to users with role "admin")
    getCurrentUser(request).then(user => {
      if (!user) {
        basicAuthChallenge(response);
      } else {
        if (user.role === 'admin'){
           const users = getAllUsers();
           return responseUtils.sendJson(response, users);
        }else {
          return responseUtils.forbidden(response);
        }
      }
    });
  }
  // And users
  if (filePath === '/api/products' && method.toUpperCase() === 'GET') {
    getCurrentUser(request).then(user => {
      if (user === null) {
        return responseUtils.basicAuthChallenge(response);
      } else {
        if (user.role === "admin" || user.role === "customer") {
          return responseUtils.sendJson(response, productdata);
        } else {
          return responseUtils.forbidden(response);
        }
      }
    });
  }


  // register new user
  if (filePath === '/api/register' && method.toUpperCase() === 'POST') {
    // Fail if not a JSON request
    if (!isJson(request)) {
      return responseUtils.badRequest(response, 'Invalid Content-Type. Expected application/json');
    }

    // TODO: 8.3 Implement registration
    // You can use parseBodyJson(request) from utils/requestUtils.js to parse request body
    // throw new Error('Not Implemented');
    const registerUser = await (parseBodyJson(request));
    const problems = validateUser(registerUser);

    // Check if there are errors in creating user and that the email is not in use allready
    if ( problems.length !== 0 || emailInUse(registerUser.email)) {
      return responseUtils.badRequest(response, "400 Bad Request");
    } else {     
      // Set new user to the resourses
      let newUser = saveNewUser(registerUser);
      newUser = updateUserRole(newUser._id, 'customer');
      return responseUtils.createdResource(response, newUser);
    }
  }
};

module.exports = { handleRequest };
