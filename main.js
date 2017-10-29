process.stdin.resume();
process.stdin.setEncoding('utf8');
var readLines = '';

function parseInt10(elem) {
  return parseInt(elem, 10);
}

process.stdin.on('data', function (chunk) {
  readLines += chunk;
});

process.stdin.on('end', function () {
  var lines = readLines.split('\n');
  var intArray = lines[0].trim().split(' ').map(parseInt10);
});
