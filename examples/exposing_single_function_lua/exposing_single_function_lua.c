
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>

// Define our function, we have to follow the protocol of lua_CFunction that is 
// typedef int (*lua_CFunction) (lua_State *L);
int multiplication(lua_State *l) {

    // Check first argument is integer and return the value
    int a = luaL_checkinteger(l, 1);

    // Check second argument is integer and return the value
    int b = luaL_checkinteger(l, 2);
    
    // multiply and store the result inside a type lua_Integer
    lua_Integer c = a * b;

    // push the result to Lua
    lua_pushinteger(l, c);

    // exit code, successful = 1, otherwise error.
    return 1; // Successful
}


int main(int argc, char ** argv) {

    lua_State *l = luaL_newstate();
    luaL_openlibs(l);

    // Push the pointer to function
    lua_pushcfunction(l, multiplication);

    // Get the value on top of the stack
    // and set as a global, in this case is the function
    lua_setglobal(l, "mul");
    
    // we can use the function `mul` inside the Lua code
    char * code = "print(mul(7, 8))";

    if (luaL_loadstring(l, code) == LUA_OK) {
        if (lua_pcall(l, 0, 1, 0) == LUA_OK) {
            lua_pop(l, lua_gettop(l));
        }
    }

    lua_close(l);
    return 0;
}
