process.stdin.resume();
process.stdin.setEncoding('utf8');

function parseInt10(elem) {
  return parseInt(elem, 10);
}

process.stdin.on('data', function (chunk) {
  var intArray = chunk.trim().split(' ').map(parseInt10);

  console.log(Math.max(intArray[0], intArray[1]));
});
