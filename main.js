process.stdin.resume();
process.stdin.setEncoding('utf8');

function parseInt10(elem) {
  return parseInt(elem, 10);
}

process.stdin.on('data', function (chunk) {
  var lines = chunk.toString().split('\n');
  var intArray = lines[0].trim().split(' ').map(parseInt10);
});
