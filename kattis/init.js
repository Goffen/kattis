var path = require('path');
var fs = require('fs');
var https = require('https');
var zlib = require('zlib');
var path = require('path');

if(process.argv.length != 3) {
	process.exit(0);
}
var problemname = process.argv[2];

https.get({
	host: 'open.kattis.com',
	path: 'problems/'+problemname+'/file/statement/samples.zip'
});

function download(url, ws) {
  var data = "";
  var request = https.get(url, function(res) {
    res.pipe(ws)
  });

  request.on('error', function(e) {
    console.log("Got error: " + e.message);
  });
}

fs.mkdirSync(problemname);
fs.copyFileSync('init.cpp', path.join(problemname, problemname+'.cpp'));
var ws = fs.createWriteStream(path.join(problemname, 'samples.zip'));
download('https://open.kattis.com/problems/'+problemname+'/file/statement/samples.zip', ws);