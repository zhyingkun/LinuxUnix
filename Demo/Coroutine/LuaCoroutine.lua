print("Start...")
function remoteCompile()
	print("In getPara Now...")
	-- do something
	coroutine.yield()
	print("In doCompile Now...")
	-- do something
	coroutine.yield()
	print("In uploadResult Now...")
	-- do something
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
