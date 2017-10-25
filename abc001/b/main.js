process.stdin.resume();
process.stdin.setEncoding('utf8');

function parseInt10(elem) {
  return parseInt(elem, 10);
}

process.stdin.on('data', function (chunk) {
  var lines = chunk.toString().split('\n');
  var m = parseInt10(lines[0]);
  var vv = 0;

  if (m < 100) {
    vv = 0;
  } else if (m >= 100 && m <= 5000) {
    vv = m / 100;
  } else if (m >= 6000 && m <= 30000) {
    vv = m / 1000 + 50;
  } else if (m >= 35000 && m <= 70000) {
    vv = (m / 1000 - 30) / 5 + 80;
  } else if (m > 70000) {
    vv = 89;
  }

  var r = ('0' + vv).slice(-2);
  console.log(r);
});
