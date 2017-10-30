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
  var intArray = readLines.trim().split(' ').map(parseInt10);

  var lines = readLines.split(' ');
  var deg = parseInt10(intArray[0]);
  var dis = parseInt10(intArray[1]);

  var theta = 36000/16;
  var dirArray = ['N', 'NNE', 'NE', 'ENE', 'E', 'ESE', 'SE', 'SSE', 'S', 'SSW', 'SW', 'WSW', 'W', 'WNW', 'NW', 'NNW'];
  var dir = dirArray[Math.floor(((deg * 10 + theta / 2) % 36000) / theta)];
  
  var power10 = Math.floor((dis * 100 / 60 + 5) / 10);
  var wArray = [[0, 2], [3, 15], [16, 33], [34, 54], [55, 79], [80, 107], [108, 138], [139, 171], [172, 207], [208, 244], [245, 284], [285, 326], [327, 2000]];
  for (var w = 0; w < wArray.length; w++) {
    if (wArray[w][0] <= power10 && power10 <= wArray[w][1])
      break;
  }

  if (w == 0)
    dir = 'C';
  
  console.log(dir + ' ' + w.toString());
});
