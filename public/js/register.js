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
        const name = document.getElementById('name').value;
        const email = document.getElementById('email').value;
        const password = document.getElementById('password').value;

        const userInfo = {
            name: name,
            email: email,
            password: password
        };
        console.log(userInfo);
        postOrPutJSON('/api/register', 'POST', user).then(response => {
            document.getElementById('register-form').reset();
        });
    }
});