var path = require('path');
var fs = require('fs');
var dir = process.argv[2];

function runProcess(input, output, fileName) {
	var spawn = require('child_process').spawn;
	 var child1 = spawn(path.join(dir, 'out'));
	 var datas = [];
	child1.stdin.setEncoding('utf-8');
	child1.stdin.write(input);
	child1.stdout.on('data', (data) => {
		datas.push(data);
	});
	child1.on('close', function() {
		var programOutput = datas.toString();
		if(process.platform === 'win32') {
			programOutput = programOutput.replace(/\r\n/g, '\n');
		}
		if(output != programOutput) {
			console.log("-------- FAILED: " + fileName + " -------");
			console.log(input.toString());
			console.log('- expected -')
			console.log(output.toString());
			console.log('- output -')
			console.log(programOutput);
			console.log("lengths= ans " + output.length + " vs output " + programOutput.length);
		}
		else {
			console.log("OK: " + fileName);
		}
	})
	child1.stdin.end();
}

fs.readdir(dir, function(err, files) {
	files.sort();
	for (var i = 0; i < files.length; i++) {
		var file = files[i];
		if(file.endsWith('.in')) {
			var fileName = file.substr(0, file.length - 3);
			runProcess(fs.readFileSync(path.join(dir, file)), fs.readFileSync(path.join(dir, fileName + ".ans")), fileName);
		}
	}
})




