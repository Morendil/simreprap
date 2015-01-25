var express = require('express');
var fs = require('fs');

var app = module.exports = express();

app.use(express.static(__dirname + '/public'));

app.use(function(err, req, res, next) {
  console.log('error: ' + err );
});

app.get('/', function(req, res) { res.redirect('/index.html') });

var lineSource = process.stdin.pipe(require('split')())

app.get('/events', function(req, res) {
  res.writeHead(200, {
    'Content-Type': 'text/event-stream',
    'Connection': 'keep-alive',
    'Cache-Control': 'no-cache',
  });

  var onData = function(data) {
    var str = data.toString('utf-8');
    //console.log("data: %s", str);
    if(str.match(/^data:/)) {
      res.write('event: steppers\n');
      res.write(str + "\n\n");
    }
  };

  lineSource.addListener('data', onData);

  // If the client disconnects, let's not leak any resources
  res.on('close', function() {
    lineSource.removeListener('data', onData);
  });
});

var http = require('http');
var server = http.createServer(app);
server.listen(process.env.PORT || 3000);
console.log("tailpipe listening on port %d in %s mode", server.address().port, app.settings.env);
