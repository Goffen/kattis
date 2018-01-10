
var spawn = require('child_process').spawn,
    child1 = spawn('out');

var spawn = require('child_process').spawn,
    child2 = spawn('out_old');

child1.stdin.setEncoding('utf-8');
child2.stdin.setEncoding('utf-8');


var l = ["a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","q","r","s","t","u","v","w","x","y","z"];


var permutations = [];
for (var i = 0; i < l.length; i++) {
	var c = l[i];
	
	for (var j = i; j < l.length; j++) {
		var c2 = l[j];
		if(j == (i + 1)) {
			permutations.push(c + " " + c2);		
		}
	}
}
permutations.push("z a");
permutations.push("h j");


function write(s) {
	child1.stdin.write(s + "\n");
	child2.stdin.write(s + "\n");
	console.log(s);
}

write(permutations.length + " 1");

for (var i = 0; i < permutations.length; i++) {
	var p = permutations[i];
	write(p);
}

write("aaaaaabbbbcccddeyzzzzzzzzzzzzzzzzz zzzzzzzzzzzzzzzzzabcdefghijklmnopq");

child1.stdout.on('data', (data) => {
  console.log(`stdout 1: ${data} ${data.toString() == 'yes\r\n'}`);
});

child2.stdout.on('data', (data) => {
  console.log(`stdout 2: ${data} ${data.toString() == 'yes\r\n'}`);
});


child1.stdin.end();
child2.stdin.end();