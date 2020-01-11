print("Start...")
local function getPara()
	print("In getPara Now...")
	-- do something
	coroutine.yield()
end
local function doCompile()
	print("In doCompile Now...")
	-- do something
	coroutine.yield()
end
local function uploadResult()
	print("In uploadResult Now...")
	-- do something
end
local function remoteCompile()
	getPara()
	doCompile()
	uploadResult()
end
local coro = coroutine.create(remoteCompile)
while true do
	coroutine.resume(coro)
	print("Check done now...")
	local status = coroutine.status(coro)
	if status == "dead" then
		break
	end
end
print("End")
