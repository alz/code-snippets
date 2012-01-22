-- Send some data into C++
result = hello_lua("foo", "bar", "baz")
-- Print out the result
io.write("Lua received: ", result, "\n")
