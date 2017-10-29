process.stdin.resume();
process.stdin.setEncoding('utf8');

function parseInt10(elem) {
  return parseInt(elem, 10);
}

process.stdin.on('data', function (chunk) {
  var n = parseInt(chunk);
  // var average = 10000.0 * (1 + n) * n / 2 / n;
  var average = 10000.0 * (1 + n) / 2;
  console.log(average);
});
