bump = require("bump")

ray = {}

function ray:isCollision(world)
	local goal = GXE_Rect.new((self.start.x+self.length)*self.dir.x, self.start.y+self.length*self.dir.y)
	local actualX, actualY, cols, len = world:move(self.body, goal.x, goal.y, touch)

	return {
		goal = goal,
		touch = GXE_Rect.new(actualX,actualY)
	}
	
end

function ray.new(start, dir, length, world)
	local self = setmetatable(ray, ray)
	self.start = GXE_Rect.new(start.x,start.y)
	self.dir = GXE_Rect.new(dir.x,dir.y)
	self.length = length
	self.curPos = GXE_Rect.new(start.x,start.y,1,1)
	self.body = {name="ray"}

	world:add(self.body, start.x, start.y, 1,1)

	return self
end

return ray