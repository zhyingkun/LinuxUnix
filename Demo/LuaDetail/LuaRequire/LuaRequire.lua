function require(modname)
	local loadedVal = package.loaded[modname]
	if loadedVal then
		return loadedVal
	end
	local errorMsg = ""
	for _, searcher in ipairs(package.searchers) do
		local loader, absPath = searcher(modname)
		local typeOfLoader = type(loader)
		if typeOfLoader == "function" then
			local ret = loader(modname, absPath)
			if ret ~= nil then
				package.loaded[modname] = ret
			end
			if package.loaded[modname] == nil then
				package.loaded[modname] = true
			end
			return package.loaded[modname]
		elseif typeOfLoader == "string" then
			errorMsg = errorMsg .. loader
		else
			-- should not run here
		end
	end
	error("module " .. modname .. " not found:" .. errorMsg)
	-- no way to here
end

function CallRequire()
	print("Start call require")
	moduleB = require("Test")
	print("After call require")
	moduleB.hello()
	moduleB.nice()
end

print("Start...")
print(pcall(CallRequire))
-- CallRequire()
print("End")
