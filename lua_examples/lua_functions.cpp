/**
 * lua_functions.cpp
 *
 * A quick example of how to export functions to lua from c++
 */

#include <iostream>
#include <lua.hpp>

using namespace std;

// Exported function to lua
int hello_lua(lua_State *state)
{
	// Get number of qrguments received
	int argc = lua_gettop(state);

	cout << "hello_lua: Received " << argc << " arg(s)" << endl;
	
	// Iterate the incoming arguments
	for (int i = 1; i <= argc; i++)
	{
		cout << "\t" << i << ": " << lua_tostring(state, i) << endl;
	}

	// Make an example return string
	string retstr("This came from c++!");

	// Push an example return argument
	lua_pushstring(state, retstr.c_str());

	// Return the number of results on the stack
	return 1;
}

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

	// Register a function with lua
	lua_register(state, "hello_lua", hello_lua);

	// Load the test file
	status = luaL_loadfile(state, "hello_functions.lua");

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
