cvs = null
ctx = null

width = 600
height = 600

window.addEventListener "load",->
  cvs = document.getElementById "canvas"
  ctx = cvs.getContext "2d"
  ctx.fillStyle = "black"
  ctx.fillRect 0,0,width,height
  do updateVis

RAND_1000 = 0
NARUSE_10000 = 1

n = 1000
type = RAND_1000
points = [rand1000_points, naruse10000_points]

scale = 2.0

updateVis = ->
  ctx.fillStyle = "black"
  ctx.fillRect 0,0,width,height

  ctx.fillStyle = "yellow"
  for i in [0...points[type].length]
    [x,y] = points[type][i]
    ctx.fillRect x*scale,y*scale,1,1
  
  text = document.getElementById("area").value
  text = text.split("\n").join(" ").split(/\s+/)
  while text.length>0 and text[text.length-1] is ""
    text.pop()
  m = text.length
  ctx.strokeStyle = "white"
  for i in [0...m]
    s = text[i]^0
    t = (if i is m-1 then text[0] else text[i+1])^0
    if s>=n or t>=n
      alert "Error"
      return
    do ctx.beginPath
    ctx.moveTo points[type][s][0]*scale, points[type][s][1]*scale
    ctx.lineTo points[type][t][0]*scale, points[type][t][1]*scale
    do ctx.stroke
  return

changeType = (val)->
  type = val
  n = points[type].length
  do updateVis

setScale = (sc)->
  scale = sc
  do updateVis

rescale = ->
  setScale (+document.getElementById("scale").value)
