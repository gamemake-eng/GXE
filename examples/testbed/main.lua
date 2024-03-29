config = {
	width = 600,
	height = 600,
	title = "Game engine maybe lol"
}
txt = {}
cam = {
	x = 0,
	y = 0,
	zoom = 1,
	speed = 200
}

t = 0
function script_path()
   local str = debug.getinfo(2, "S").source:sub(2)
   return str:match("(.*/)")
end
str = "Hello there! Welcome to GXE!"
function init( )
	
	camTrans = GXE_Transform.new()
	font = GXE_Font.new("lazy.ttf", 20)
	font2 = GXE_Font.new("lovedays.ttf", 20)
	font3 = GXE_Font.new()

	img = GXE_Image.new("dude.png")
	img.crop.w = 30

	view = GXE_View.new(GXE_Rect.new(0,0,300,600))

	rect1 = GXE_Rect.new(0,0,20,20)
	rect2 = GXE_Rect.new(-30,30,200,400)
	playerspeed = GXE_Rect.new(0,0)
	d = 0
	
	x = 0
	y = 0

	cam.x = cam.x + 0.1

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

	--rect1.x = rect1.x + 20 * dt

	

	for k,v in pairs(txt) do

		v.x = v.x + (20) * dt;
		if v.x > config.width then
			v.x = -10
			
		end
	end

	t = t + 1

	targetx = rect1.x - ((config.width)/2) / cam.zoom
	targety = rect1.y - ((config.height)/2) / cam.zoom

	cam.x = cam.x + (targetx - cam.x) * dt
	cam.y = cam.y + (targety - cam.y) * dt

	--[[if GXE_Input.KeyJustPress(GXE_Input.KEY_UP) then
		playerspeed.y = -cam.speed * dt
	elseif GXE_Input.KeyDown(GXE_Input.KEY_DOWN) then
		playerspeed.y =  cam.speed * dt
	else
		playerspeed.y = 0
	end]]--

	rect1.x = rect1.x + playerspeed.x
	if GXE_Rect.CheckAABB(rect1, rect2) then
		if not (playerspeed.y == 0) then
			rect1.x = rect1.x - playerspeed.x
		end
	end

	rect1.y = rect1.y + playerspeed.y
	if GXE_Rect.CheckAABB(rect1, rect2) then
		rect1.y = rect1.y - playerspeed.y
	end

	if GXE_Input.KeyDown(GXE_Input.KEY_LEFT) then
		playerspeed.x = -cam.speed * dt
	elseif GXE_Input.KeyDown(GXE_Input.KEY_RIGHT) then
		playerspeed.x = cam.speed * dt
	else
		playerspeed.x = 0
	end

	side = GXE_Rect.MoveAndDetect(rect1, playerspeed, rect2, GXE_Rect.new(0,0))

	if side == "up" then
		playerspeed.y = 0
	else
		playerspeed.y = playerspeed.y + 0.01
	end

	

	--cam.zoom = cam.zoom - 0.01

end
a = 0
function draw( )
	GXE_Graphics.ClearScreen(GXE_Color.MonogameBlue)
	drawgame(GXE_Color.ReallyGreen)
	GXE_Graphics.SetView(view)
	GXE_Graphics.ClearScreen(GXE_Color.BloodShotRed)
	drawgame(GXE_Color.EyeStrainBlue)
	GXE_Graphics.RestoreView()

	GXE_Graphics.DrawView(view, 0, 0)
end

function drawgame(c)
	a = a + 0.01
	
	

	camTrans:Push()
	camTrans:Translate(cam.x, cam.y)
	camTrans:Scale(cam.zoom, cam.zoom)
	local crop = GXE_Rect.new(0,0,30,30)

	if GXE_Rect.CheckAABB(rect1, rect2) then
		GXE_Graphics.DrawRect(rect1, GXE_Color.ReallyGreen)
	else
		GXE_Graphics.DrawRect(rect1, c)
	end

	GXE_Graphics.DrawRect(rect2, c)


	GXE_Graphics.PauseDraw(true)
	for k,v in pairs(txt) do
		GXE_Graphics.DrawText(v.char, v.x, v.y,c, font)
		GXE_Graphics.DrawText(v.char, v.x, v.y+30,c, font2)
		GXE_Graphics.DrawText(v.char, v.x, v.y+60,c, font3)
	end
	
	GXE_Graphics.PauseDraw(false)

	camTrans:Pop()
	GXE_Graphics.DrawText(""..playerspeed.x, 0, 0,GXE_Color.ReallyGreen, font2)

	if GXE_Input.KeyDown(62) then
		cam.zoom = cam.zoom + 0.01
	end
	if GXE_Input.KeyDown(61) then
		cam.zoom = cam.zoom - 0.01
	end
end