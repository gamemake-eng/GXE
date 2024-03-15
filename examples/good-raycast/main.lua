config = {
	width = 600,
	height = 600,
	title = "Game engine maybe lol"
}
local bump = require 'bump'
local ray = require("ray")
--[[
WARNING: THIS IS GARBAGE, LESS LAGGY
]]
function init(  )

	playerRect = GXE_Rect.new(0,0,20,20)
	colpos = GXE_Rect.new(0,0)

	dir = GXE_Rect.new(0,0)

	wallRect = GXE_Rect.new(50,50,100,100)

	playerBody = {name="player"}
	wallBody = {name="wall"}

	world = bump.newWorld(50)

	ray1 = ray.new(playerRect, GXE_Rect.new(1,0), 100, world)

	world:add(playerBody, playerRect.x, playerRect.y, playerRect.w, playerRect.h)
	world:add(wallBody, wallRect.x, wallRect.y, wallRect.w, wallRect.h)
end

function update( dt )
	ray1.dir.x = dir.x
	ray1.dir.y = dir.y
	ray1.start.x = playerRect.x
	ray1.start.y = playerRect.y
	col = ray1:isCollision(world)
	colpos.x = col.touch.x
	colpos.y = col.touch.y
	ax, ay, cols, len = world:move(playerBody, playerRect.x, playerRect.y, slide)
	playerRect.x = ax
	playerRect.y = ay

	if GXE_Input.KeyDown(GXE_Input.KEY_LEFT) then
		playerRect.x = playerRect.x- 100 * dt
		dir.x = -1
	elseif GXE_Input.KeyDown(GXE_Input.KEY_RIGHT) then
		playerRect.x = playerRect.x+ 100 * dt
		dir.x = 1
	
	end

	if GXE_Input.KeyDown(GXE_Input.KEY_UP) then
		playerRect.y = playerRect.y- 100 * dt
	elseif GXE_Input.KeyDown(GXE_Input.KEY_DOWN) then
		playerRect.y = playerRect.y+ 100 * dt
	
	end
end

function draw(  )
	GXE_Graphics.ClearScreen(GXE_Color.MonogameBlue)
	
	GXE_Graphics.DrawRect(playerRect, GXE_Color.ReallyGreen)
	GXE_Graphics.DrawRect(wallRect, GXE_Color.ReallyGreen)
	GXE_Graphics.DrawCircle(colpos, 5, GXE_Color.BloodShotRed)
	
end