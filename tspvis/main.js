// Generated by CoffeeScript 1.10.0
var NARUSE_10000, RAND_1000, changeType, ctx, cvs, height, n, points, rescale, scale, setScale, type, updateVis, width;

cvs = null;

ctx = null;

width = 600;

height = 600;

window.addEventListener("load", function() {
  cvs = document.getElementById("canvas");
  ctx = cvs.getContext("2d");
  ctx.fillStyle = "black";
  ctx.fillRect(0, 0, width, height);
  return updateVis();
});

RAND_1000 = 0;

NARUSE_10000 = 1;

n = 1000;

type = RAND_1000;

points = [rand1000_points, naruse10000_points];

scale = 2.0;

updateVis = function() {
  var i, j, k, m, ref, ref1, ref2, s, t, text, x, y;
  ctx.fillStyle = "black";
  ctx.fillRect(0, 0, width, height);
  ctx.fillStyle = "yellow";
  for (i = j = 0, ref = points[type].length; 0 <= ref ? j < ref : j > ref; i = 0 <= ref ? ++j : --j) {
    ref1 = points[type][i], x = ref1[0], y = ref1[1];
    ctx.fillRect(x * scale, y * scale, 1, 1);
  }
  text = document.getElementById("area").value;
  text = text.split("\n").join(" ").split(/\s+/);
  while (text.length > 0 && text[text.length - 1] === "") {
    text.pop();
  }
  m = text.length;
  ctx.strokeStyle = "white";
  for (i = k = 0, ref2 = m; 0 <= ref2 ? k < ref2 : k > ref2; i = 0 <= ref2 ? ++k : --k) {
    s = text[i] ^ 0;
    t = (i === m - 1 ? text[0] : text[i + 1]) ^ 0;
    if (s >= n || t >= n) {
      alert("Error");
      return;
    }
    ctx.beginPath();
    ctx.moveTo(points[type][s][0] * scale, points[type][s][1] * scale);
    ctx.lineTo(points[type][t][0] * scale, points[type][t][1] * scale);
    ctx.stroke();
  }
};

changeType = function(val) {
  type = val;
  n = points[type].length;
  return updateVis();
};

setScale = function(sc) {
  scale = sc;
  return updateVis();
};

rescale = function() {
  return setScale(+document.getElementById("scale").value);
};
