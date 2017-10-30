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
  var array = [];
  for (var i = 0; i < 4; i++) {
    array[i] = lines[i].trim().split(' ');
  }

  for (var i = 3; i >= 0; i--) {
    var line = '';
    for (var j = 3; j >= 0; j--) {
      line += array[i][j] + ' ';
    }
    console.log(line.trim());
  }
});
