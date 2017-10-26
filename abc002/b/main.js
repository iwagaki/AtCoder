process.stdin.resume();
process.stdin.setEncoding('utf8');

function parseInt10(elem) {
  return parseInt(elem, 10);
}

process.stdin.on('data', function (chunk) {
  var w = chunk.trim();

  w = w.replace(/[aiueo]/g, '');
  console.log(w);
});
