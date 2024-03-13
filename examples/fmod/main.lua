config = {
	width = 600,
	height = 600,
	title = "Game engine maybe lol"
}
fmod = require("fmodlua")
--[[
Made using FMOD Studio by Firelight Technologies Pty Ltd.

NOTE: This uses a 
]]--
function init( )
	
	fmod.Load()

	fmod.Play("music.wav")
end

function update(dt)
	font3 = GXE_Font.new()
end

function draw( )
	GXE_Graphics.ClearScreen(GXE_Color.MonogameBlue)
	GXE_Graphics.DrawText("You should be hearing some nice music!", 0, 0,GXE_Color.ReallyGreen, font2)
end

function exit(  )
	fmod.Release()
end