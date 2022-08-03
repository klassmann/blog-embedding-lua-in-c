
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>

// Define our function, we have to follow the protocol of lua_CFunction that is 
// typedef int (*lua_CFunction) (lua_State *L);
int multiplication(lua_State *L) {

    // Check first argument is integer and return the value
    int a = luaL_checkinteger(L, 1);

    // Check second argument is integer and return the value
    int b = luaL_checkinteger(L, 2);
    
    // multiply and store the result inside a type lua_Integer
    lua_Integer c = a * b;

    // Here we prepare the values to be returned.
    // First we push the values we want to return onto the stack in direct order.
    // Second, we must return the number of values pushed onto the stack.

    // Pushing the result onto the stack to be returned
    lua_pushinteger(L, c);

    return 1; // The number of returned values
}


int main(int argc, char ** argv) {

    lua_State *L = luaL_newstate();
    luaL_openlibs(L);

    // Push the pointer to function
    lua_pushcfunction(L, multiplication);

    // Get the value on top of the stack
    // and set as a global, in this case is the function
    lua_setglobal(L, "mul");
    
    // we can use the function `mul` inside the Lua code
    char * code = "print(mul(7, 8))";

    if (luaL_dostring(L, code) == LUA_OK) {
        lua_pop(L, lua_gettop(L));
    }

    lua_close(L);
    return 0;
}
