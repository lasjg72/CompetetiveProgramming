global.fetch = require('node-fetch');
fetch('https://api.aoikujira.com/time/get.php')
  .then(response => response.text())
  .then(data => console.log(data));