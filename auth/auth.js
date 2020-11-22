const { getCredentials } = require("../utils/requestUtils");
const  getUser  = require("../models/user");
const email = 0;
const password = 1;
/**
 * Get current user based on the request headers
 *
 * @param {http.IncomingMessage} request
 * @returns {Object|null} current authenticated user or null if not yet authenticated
 */
const getCurrentUser = async request => {
  // TODO: 8.4 Implement getting current user based on the "Authorization" request header

  // NOTE: You can use getCredentials(request) function from utils/requestUtils.js
  // and getUser(email, password) function from utils/users.js to get the currently
  // logged in user
  //throw new Error('Not Implemented');
  const credentials = getCredentials(request);

  // Check if there are not credentials 
  if ( credentials === null){ return null; }
  
  // Get user
  const user = await getUser.findOne({email: credentials[email]}).exec();

  if ( user ) {
    if ( await user.checkPassword(credentials[password])){
        return user;
    } else{ return null; } 
  } else { return null; }
};

module.exports = { getCurrentUser };
