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
  var s = lines[0].trim();
  var t = lines[1].trim();

  var isMatched = true;
  var candidates = ['a', 't', 'c', 'o', 'd', 'e', 'r'];

  for (var i = 0; i < s.length; i++) {
    if (s[i] == t[i])
      continue;
      
    if (s[i] == '@' && candidates.indexOf(t[i]) >= 0)
      continue;

    if (t[i] == '@' && candidates.indexOf(s[i]) >= 0)
      continue;

    isMatched = false;
    break;
  }

  if (isMatched)
    console.log('You can win');
  else
    console.log('You will lose');
});
