ray = {}

function ray:isCollision(obj)
	
	for i=0,self.i do
		-- Normalize vectors
		if self.dir.x > 0 then
			self.dir.x = 1
		elseif self.dir.x < 0 then
			self.dir.x = -1
		else
			self.dir.x = 0
		end
		if self.dir.y > 0 then
			self.dir.y = 1
		elseif self.dir.y < 0 then
			self.dir.y = -1
		else
			self.dir.y = 0
		end
		-- Move vector forward
		self.curPos.x = self.curPos.x + self.length * self.dir.x
		self.curPos.y = self.curPos.y + self.length * self.dir.y
		--check for collision, if true reset and return true
		if GXE_Rect.CheckAABB(self.curPos, obj) then
			local posHit = GXE_Rect.new(self.curPos.x, self.curPos.y)
			self.curPos.x = self.start.x
			self.curPos.y = self.start.y
			
			return {
				result = true,
				position = posHit
			}

		end
		
	end
	
			local posHit = GXE_Rect.new(self.curPos.x, self.curPos.y)
			self.curPos.x = self.start.x
			self.curPos.y = self.start.y
			return {
				result = GXE_Rect.CheckAABB(self.curPos, obj),
				position = posHit
			}
	
	
end
function ray:reset()
	self.curPos.x = self.start.x
	self.curPos.y = self.start.y
end
function ray.new(start, dir, length, i)
	local self = setmetatable(ray, ray)
	self.start = GXE_Rect.new(start.x,start.y)
	self.dir = GXE_Rect.new(dir.x,dir.y)
	self.length = length
	self.i = i
	self.curPos = GXE_Rect.new((start.x+length)*dir.x,start.y,1,1)
	return self
end

return ray