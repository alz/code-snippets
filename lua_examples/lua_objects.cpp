/**
 * lua_functions.cpp
 *
 * A quick example of how to export functions to lua from c++
 */

#include <iostream>
#include <luabind/luabind.hpp>
#include <lua.hpp>

using namespace std;

class LuaTest
{
  string _str;
public:
  LuaTest(string& str)
  {
    _str = str;
  }

  string getString()
  {
    return _str;
  }
};

// Function to print lua errors
void print_error(lua_State *state)
{
	// Print the error from position -1 on the stack
	cerr << "Error: " << lua_tostring(state, -1) << endl;

	// Remove the error from the stack
	lua_pop(state, 1);
}

int main()
{
	// Set up a Lua state
	lua_State *state = luaL_newstate();
	
	// Holder for command status
	int status;

	// Load the standard libraries
	luaL_openlibs(state);

	// Bind object to lua
	luabind::open(state);
	luabind::module(state) [
		// Map object to lua for direct access
		luabind::class_<LuaTest>("LuaTest")
      .def(luabind::constructor<string>()) 
			.def("getString", &LuaTest::getString)
	];

	// Load the test file
	status = luaL_loadfile(state, "hello_objects.lua");

	// Check file was successfully loaded
	if (status == 0)
	{
		// Run the lua code
		status = lua_pcall(state, 0, 0, 0);

		if (status != 0)
			print_error(state);	
	}
	else
	{
		// Something didn't work, parse error?
		print_error(state);
	}

	lua_close(state);
		
	return 0;
}
