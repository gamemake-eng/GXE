config = {
	width = 600,
	height = 600,
	title = "Game engine maybe lol"
}


--[[
GXE has simple apis for drawing rectangles, circles, and lines.
NOTE: Rects can also be used for positional infomation. You only need 2 params (x, y) to
initialze a rect. That is why we use them on the circle and line objects.
]]
function init(  )
	rect = GXE_Rect.new(10,10,50,50)
	circ = GXE_Rect.new(100,100)
	p1 = GXE_Rect.new(0,0)
	p2 = GXE_Rect.new(600,600)
	r = 10
	mode = true
end

function update( dt )
	rect.x = rect.x + 100 * dt

	if rect.x > 600 then
		rect.x = -60
	end
	if r > 50 then
		mode = false
	end
	if r < 10 then
		mode = true
	end
	if mode then
		r = r + 20 * dt
	else
		r = r - 20 * dt
	end

	circ.x = r*2
end

function draw(  )
	GXE_Graphics.ClearScreen(GXE_Color.MonogameBlue)
	GXE_Graphics.DrawLine(p1, p2, r, GXE_Color.BloodShotRed)
	GXE_Graphics.DrawRect(rect, GXE_Color.ReallyGreen)
	GXE_Graphics.DrawCircle(circ, r, GXE_Color.ReallyGreen)
end