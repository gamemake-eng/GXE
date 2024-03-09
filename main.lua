config = {
	width = 600,
	height = 600,
	title = "Game engine maybe lol"
}
txt = {}

function script_path()
   local str = debug.getinfo(2, "S").source:sub(2)
   return str:match("(.*/)")
end
str = "Hello there! Welcome to GXE!"
function init( )
	font = GXE_Font.new("lazy.ttf", 20)
	font2 = GXE_Font.new("lovedays.ttf", 20)
	font3 = GXE_Font.new()
	d = 0
	
	x = 0
	y = 0

	for i=1,#str do
		
			pos = {
				x = i*10,
				y = 0,
				char = str:sub(i,i)
			}
			
			table.insert(txt,pos)
		
	end
end
function update(dt)
	
	x = x + 1
	y = math.sin(x*100)

	

	for k,v in pairs(txt) do
		v.x = v.x + 1;
		if v.x > config.width then
			v.x = -10
		end
	end

end
function draw( )
	GXE_Graphics.ClearScreen(GXE_Color.MonogameBlue);

	for k,v in pairs(txt) do
		font:DrawText(v.char, v.x, v.y);
		font2:DrawText(v.char, v.x, v.y+30);
		font3:DrawText(v.char, v.x, v.y+60);
	end


end