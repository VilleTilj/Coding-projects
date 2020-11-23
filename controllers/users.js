const { getCurrentUser } = require('../auth/auth');
const { basicAuthChallenge, createdResource, notFound, sendJson, badRequest, unauthorized, forbidden} = require('../utils/responseUtils');
const getUser = require('../models/user');
var ObjectId = require('mongodb').ObjectID;


/**
 * Send all users as JSON
 *
 * @param {http.ServerResponse} response
 */
const getAllUsers = async response => {
  // TODO: 10.1 Implement this
  //throw new Error('Not Implemented');
  const users = await getUser.find({});
  return sendJson(response, users);
  
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
    if (userId) {
      if ( userId._id === currentUser._id) {
        return badRequest(response, '400 Bad Request');
      } else {
        const deleteUser = await getUser.findOneAndDelete({"_id": ObjectId("userId._id")}.exec());
        return sendJson(response, deleteUser); 
      }
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
  if ( currentUser.role === 'admin') {
    const reqUser = await getUser.findById(userId).exec();
    if (reqUser) {
      if ( userId === currentUser._id) {
        return badRequest(response, '400 Bad Request');
      } else {
        // if role can be found
        if (userData.role) {
          try {            
            reqUser.role = userData.role;
            await reqUser.save();
            return sendJson(response, reqUser);
          }
          catch (err) { badRequest(response, err);}
        } else { 
          return badRequest(response);
        }
      }
    }
    else {
      return notFound(response);
    }
  } else {
    return forbidden(response);
  }
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
      const reqUser = await getUser.findById(userId).exec();
      if (reqUser) {
        return sendJson(response, reqUser);
      } else {
        return notFound(response);
      }
    } else {
      return notFound(response);
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
    // Fail if not a JSON request

    // Get user
     const newUser = new getUser(userData);
     // attempt to register new user (save the document)
     // all newly registered users should be customers
     const emailUser = await getUser.findOne({ email: newUser.email }).exec();
     if (emailUser !== null) {
         return badRequest(response, '400 Bad Request');
     }
     try {
         newUser.role = 'customer';
         const registereduser = await newUser.save();
         return createdResource(response, registereduser);
     }
     catch (error) {
         return badRequest(response, '400 Bad Request');
     }
};

module.exports = { getAllUsers, registerUser, deleteUser, viewUser, updateUser };
