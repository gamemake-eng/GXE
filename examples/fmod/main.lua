config = {
	width = 600,
	height = 600,
	title = "Game engine maybe lol"
}
fmod = require("fmodstudiolua")
--[[
Made using FMOD Studio by Firelight Technologies Pty Ltd.

NOTE: This uses a lua C module not included in the repo.
You can get fmodlua here: https://github.com/gamemake-eng/FMOD-lua
]]--
hasp = false
function init( )
	
	fmod.Load("live")

	fmod.LoadBank("Desktop/Master.bank", "masterbank")
	fmod.LoadBank("Desktop/Master.strings.bank", "masterbankstr")

	
	
	font = GXE_Font.new()
end

function update(dt)
	fmod.Update()
	if GXE_Input.KeyDown(GXE_Input.KEY_LEFT) then
		if hasp == false then
			fmod.OneShot("event:/Music")
			hasp = true
		end
	else
		hasp = false
	end
end

function draw( )
	
	GXE_Graphics.ClearScreen(GXE_Color.MonogameBlue)
	GXE_Graphics.DrawText("You should be hearing some nice music when pressing left!", 0, 0,GXE_Color.ReallyGreen, font)
end

function exit(  )
	fmod.ReleaseBank("masterbank")
	fmod.ReleaseBank("masterbankstr")
	fmod.Release()
end