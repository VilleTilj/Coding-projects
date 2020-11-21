const productdata = require('../products.json');
const { getCurrentUser } = require('../auth/auth');
const { basicAuthChallenge, notFound, sendJson, badRequest, unauthorized, forbidden} = require('../utils/responseUtils');
const getUser = require('../models/user');

/**
 * Send all users as JSON
 *
 * @param {http.ServerResponse} response
 */
const getAllUsers = async response => {
  // TODO: 10.1 Implement this
  //throw new Error('Not Implemented');
  const user = await getCurrentUser(request);
  if (user === null) {
    basicAuthChallenge(response);
  } else {
    if (user.role === 'admin'){
      const users = await getUser.find({});
      return sendJson(response, users);
    }else {
      return forbidden(response);
    }
};

/**
 * Delete user and send deleted user as JSON
 *
 * @param {http.ServerResponse} response
 * @param {string} userId
 * @param {Object} currentUser (mongoose document object)
 */
const deleteUser = async (response, userId, currentUser) => {
  // TODO: 10.1 Implement this
  if ( currentUser.role === 'admin') {
    const reqUser = await getUser.findOById(userId).exec();
    if (reqUser) {
      const deleteUser = await getUser.findOneAndDelete({_id: reqUser._id}.exec());
      return sendJson(response, deleteUser); 
    }
    else {
      return notFound(response);
    }
  } else {
    return forbidden(response);
  }
};

/**
 * Update user and send updated user as JSON
 *
 * @param {http.ServerResponse} response
 * @param {string} userId
 * @param {Object} currentUser (mongoose document object)
 * @param {Object} userData JSON data from request body
 */
const updateUser = async (response, userId, currentUser, userData) => {
  // TODO: 10.1 Implement this
  throw new Error('Not Implemented');
};

/**
 * Send user data as JSON
 *
 * @param {http.ServerResponse} response
 * @param {string} userId
 * @param {Object} currentUser (mongoose document object)
 */
const viewUser = async (response, userId, currentUser) => {
  // TODO: 10.1 Implement this
  //throw new Error('Not Implemented');
  if ( currentUser.role === 'admin') {
      const reqUser = await getUser.findOById(userId).exec();
    if (reqUser) {
      return responseUtils.sendJson(response, reqUser);
    } else {
      return notFound(response);
    }
  } else {
    return forbidden(response);
  }

};

/**
 * Register new user and send created user back as JSON
 *
 * @param {http.ServerResponse} response
 * @param {Object} userData JSON data from request body
 */
const registerUser = async (response, userData) => {
  // TODO: 10.1 Implement this
  throw new Error('Not Implemented');
};

module.exports = { getAllUsers, registerUser, deleteUser, viewUser, updateUser }};
