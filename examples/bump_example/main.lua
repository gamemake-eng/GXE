config = {
	width = 600,
	height = 600,
	title = "Game engine maybe lol"
}
local bump = require 'bump'
--[[
This shows how you can use libraies like BUMP in your games
]]
function init(  )
	font = GXE_Font.new()

	cam = GXE_Camera.new(config.width, config.height)

	playerRect = GXE_Rect.new(0,0,20,20)

	wallRect = GXE_Rect.new(50,50,100,100)

	playerBody = {name="player"}
	wallBody = {name="wall"}

	world = bump.newWorld(50)

	world:add(playerBody, playerRect.x, playerRect.y, playerRect.w, playerRect.h)
	world:add(wallBody, wallRect.x, wallRect.y, wallRect.w, wallRect.h)

end

function update( dt )
	cam:CenterTarget(playerRect, dt)
	ax, ay, cols, len = world:move(playerBody, playerRect.x, playerRect.y, touch)
	playerRect.x = ax
	playerRect.y = ay

	if GXE_Input.KeyDown(GXE_Input.KEY_LEFT) then
		playerRect.x = playerRect.x- 100 * dt
	elseif GXE_Input.KeyDown(GXE_Input.KEY_RIGHT) then
		playerRect.x = playerRect.x+ 100 * dt
	
	end

	if GXE_Input.KeyDown(GXE_Input.KEY_UP) then
		playerRect.y = playerRect.y- 100 * dt
	elseif GXE_Input.KeyDown(GXE_Input.KEY_DOWN) then
		playerRect.y = playerRect.y+ 100 * dt
	
	end
end

function draw(  )
	GXE_Graphics.ClearScreen(GXE_Color.MonogameBlue)
	cam:Mount()
	GXE_Graphics.DrawText("[Arrow keys] You should stop moving when touching the green square", 50, -10, GXE_Color.BloodShotRed, font)
	GXE_Graphics.DrawRect(playerRect, GXE_Color.ReallyGreen)
	GXE_Graphics.DrawRect(wallRect, GXE_Color.ReallyGreen)
	cam:Unmount()
end