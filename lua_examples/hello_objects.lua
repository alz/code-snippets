-- Send some data into C++
test = LuaTest("Hello, World!");
result = test:getString()--("Hello from Lua!")
-- Print out the result
io.write("Object returned: ", result, "\n")
