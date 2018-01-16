var path = require('path');
var fs = require('fs');
//if(process.argv.length != 3) {
//	process.exit(0);
//}
var dir = process.argv[2];

function runProcess(input, output, indx) {
	var spawn = require('child_process').spawn;
    var child1 = spawn(path.join(dir, 'out'));
    var datas = [];
	child1.stdin.setEncoding('utf-8');
	child1.stdin.write(input);
	child1.stdout.on('data', (data) => {
		datas.push(data);
	  	//console.log(`${indx}: ${data} ${data.toString() == 'yes\r\n'}`);
	});
	child1.on('close', function() {
		console.log("-------- " + indx + " -------");
		console.log(input.toString());
		//var windowsOutput = output.toString().replace(/\n/g, '\r\n');
		console.log('- expected -')
		console.log(output.toString());
		console.log('- output -')
      	var programOutput = datas.toString();
		console.log(programOutput);
		console.log("lengths= ans " + output.length + " vs output " + programOutput.length);
		console.log("equals=" + (output == programOutput));

	})
	child1.stdin.end();
}

fs.readdir(dir, function(err, files) {
	files.sort();
	var samples = 0;
	for (var i = 0; i < files.length; i++) {
		var file = files[i];
		if(file.endsWith('.in')) {
			var indx = parseInt(file.substring(0, file.indexOf('.')));
			samples = indx;
		}
	}
	for (var i = 1; i <= samples; i++) {
		runProcess(fs.readFileSync(path.join(dir, i + ".in")), fs.readFileSync(path.join(dir, i + ".ans")), i);
	}
})




