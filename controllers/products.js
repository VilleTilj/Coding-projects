const productdata = require('../products.json');
const { getCurrentUser } = require('../auth/auth');
const { sendJson, forbidden} = require('../utils/responseUtils');




/**
 * Send all products as JSON
 *
 * @param {http.ServerResponse} response
 */
const getAllProducts = async response => {
  // TODO: 10.1 Implement this
  // throw new Error('Not Implemented');
  return sendJson(response, productdata);
};

module.exports = { getAllProducts };
