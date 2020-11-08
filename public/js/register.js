/**
 * TODO: 8.3 Register new user
 *       - Handle registration form submission
 *       - Prevent registration when password and passwordConfirmation do not match
 *       - Use createNotification() function from utils.js to show user messages of
 *       - error conditions and successful registration
 *       - Reset the form back to empty after successful registration
 *       - Use postOrPutJSON() function from utils.js to send your data back to server
 */
document.getElementById('btnRegister').addEventListener('click', function(event) {  
    event.preventDefault(); 
    // checking if password and password confirmation match
    if (document.getElementById('password').value != document.getElementById('passwordConfirmation').value){
        // if they don't, send notification to user
        createNotification('Password and password confirmation do not match', 'notifications-container');
        
    } else {

        // saving all info to variables for easier use
        var name = document.getElementById('name').value;
        var email = document.getElementById('email').value;
        var password = document.getElementById('password').value;

        const user = {
            name: name,
            email: email,
            password: password
        };

        console.log(user);
        // POST request 
        postOrPutJSON('/api/register','POST', user).then(response => {
            // console.log(response); // this should be the new user
            document.getElementById('register-form').reset();
        });
    }
})