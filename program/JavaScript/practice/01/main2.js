
var XMLHttpRequest = require("xmlhttprequest").XMLHttpRequest;
var request = new XMLHttpRequest()

request.open('GET', 'https://jsonplaceholder.typicode.com/users/1', true);
request.responseType = 'json';

request.onload = function () {
    var data = this.response;
    console.log(data);
};

request.send();