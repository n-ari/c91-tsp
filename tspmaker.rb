reso = 1000.0
maxx = 300.0

# naruse10000.in
require 'RMagick'
include Magick

img = ImageList.new("./narusetsp.bmp")

w = img.columns
h = img.rows
n = 10000

ans = []
srand(83025)
for i in 0...n
  while true
    x = rand(w * reso)/reso
    y = rand(h * reso)/reso
    xi = x.to_i
    yi = y.to_i
    src = img.pixel_color(x,y)
    # puts "#{src.red} #{src.green} #{src.blue}"
    if (src.red==65535 && src.green==65535 && src.blue==65535)
      x = x / w * maxx
      y = y / h * maxx
      ans.push [x,y]
      break
    end
  end
end

File.open("naruse10000.in", "w") do |f|
  f.puts "#{n}"
  for pa in ans
    f.puts "#{format("%.4f",pa[0])} #{format("%.4f",pa[1])}"
  end
end
File.open("naruse10000.js", "w") do |f|
  f.puts "var naruse10000_points = ["
  for i in 0...ans.length
    pa = ans[i]
    f.puts "  [#{format("%.4f",pa[0])}, #{format("%.4f",pa[1])}]#{i != ans.length-1 ? "," : ""}"
  end
  f.puts "];"
end

# rand1000.in
n = 1000
ans = []
srand(252521)
for i in 0...n
  x = rand(maxx * reso)/reso
  y = rand(maxx * reso)/reso
  ans.push [x,y]
end

File.open("rand1000.in", "w") do |f|
  f.puts "#{n}"
  for pa in ans
    f.puts "#{format("%.4f",pa[0])} #{format("%.4f",pa[1])}"
  end
end
File.open("rand1000.js", "w") do |f|
  f.puts "var rand1000_points = ["
  for i in 0...ans.length
    pa = ans[i]
    f.puts "  [#{format("%.4f",pa[0])}, #{format("%.4f",pa[1])}]#{i != ans.length-1 ? "," : ""}"
  end
  f.puts "];"
end
