const productdata = require('../products.json');
const { getCurrentUser } = require('../auth/auth');
const { basicAuthChallenge, notFound, sendJson, badRequest, unauthorized, forbidden} = require('../utils/responseUtils');




/**
 * Send all products as JSON
 *
 * @param {http.ServerResponse} response
 */
const getAllProducts = async response => {
  // TODO: 10.1 Implement this
  // throw new Error('Not Implemented');
  const user = await getCurrentUser(request);
      if (user === null || typeof user === 'undefined') {
        return responseUtils.basicAuthChallenge(response);
      } else {
        if (user.role === "admin" || user.role === "customer") {
          return sendJson(response, productdata);
        } else {
          return forbidden(respponse);
        }
      }
};

module.exports = { getAllProducts };
