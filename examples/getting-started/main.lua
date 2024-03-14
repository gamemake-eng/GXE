config = {
	width = 600,
	height = 600,
	title = "Game!"
}

function init(  )
	rect = GXE_Rect.new(0,0,32,32)
	speed = GXE_Rect.new(0,0)
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

end
function draw(  )
	GXE_Graphics.ClearScreen(GXE_Color.MonogameBlue)
	GXE_Graphics.DrawRect(rect, GXE_Color.ReallyGreen)
	
end