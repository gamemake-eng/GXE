config = {
	width = 600,
	height = 600,
	title = "Raycast example!"
}
ray = require("ray")
--[[
WARNING: WILL FRY YOUR COMPUTER!!!!!
]]
function init(  )
	cubes = {}
	rect = GXE_Rect.new(0,300,32,32)
	for i=1,10 do
		table.insert(cubes,GXE_Rect.new(300+(i*32),300+(i*32),32,32))
	end
	rect2 = GXE_Rect.new(300,300,32,32)
	colPoint = GXE_Rect.new(0,0)
	speed = GXE_Rect.new(0,0)

	ray1 = ray.new(GXE_Rect.new(0,300), GXE_Rect.new(1,0), 1, 100)
	
	

	walk_speed = 200
end

function update( dt )
	rect.x = rect.x + speed.x
	rect.y = rect.y + speed.y
	if GXE_Input.KeyDown(GXE_Input.KEY_UP) then
		speed.y = -walk_speed * dt
	elseif GXE_Input.KeyDown(GXE_Input.KEY_DOWN) then
		speed.y = walk_speed * dt
	else
		speed.y = 0
	end
	if GXE_Input.KeyDown(GXE_Input.KEY_LEFT) then
		speed.x = -walk_speed * dt
	elseif GXE_Input.KeyDown(GXE_Input.KEY_RIGHT) then
		speed.x = walk_speed * dt
	else
		speed.x = 0
	end

	ray1.start.x = rect.x + (rect.w/2)
	ray1.start.y = rect.y + (rect.h/2)
	ray1.dir.x = speed.x
	ray1.dir.y = speed.y
	if (speed.x > 0) or (speed.y > 0) or (speed.x < 0) or (speed.y < 0) then
		for i=1,#cubes do
			local v = cubes[i]
			colD = ray1:isCollision(v)
		end

		colPoint.x = colD.position.x
		colPoint.y = colD.position.y
	end



	

end
function draw(  )
	GXE_Graphics.ClearScreen(GXE_Color.MonogameBlue)
	GXE_Graphics.DrawLine(ray1.start, colPoint, 2, GXE_Color.BloodShotRed)
	GXE_Graphics.DrawCircle(colPoint, 5, GXE_Color.BloodShotRed)
	for k,v in pairs(cubes) do
		GXE_Graphics.DrawRect(v, GXE_Color.ReallyGreen)
	end
	GXE_Graphics.DrawRect(rect, GXE_Color.ReallyGreen)
	GXE_Graphics.DrawRect(rect2, GXE_Color.ReallyGreen)

	
	
	
end