/**
 * lua_hello.cpp
 *
 * A quick basic example of how to integrate your c++ application
 * with Lua
 */

#include <iostream>
#include <lua.hpp>

using namespace std;

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

	// Load the test file
	status = luaL_loadfile(state, "hello.lua");

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
