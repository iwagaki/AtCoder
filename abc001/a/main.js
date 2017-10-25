process.stdin.resume();
process.stdin.setEncoding('utf8');

function parseInt10(elem) {
  return parseInt(elem, 10);
}

process.stdin.on('data', function (chunk) {
  var lines = chunk.toString().split('\n');
  var h1 = parseInt10(lines[0]);
  var h2 = parseInt10(lines[1]);
  console.log(h1 - h2);
});
