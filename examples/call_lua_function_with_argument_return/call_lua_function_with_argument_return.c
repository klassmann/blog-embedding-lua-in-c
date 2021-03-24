#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>

int main(int argc, char ** argv) {

    lua_State *L = luaL_newstate();
    luaL_openlibs(L);

    if (luaL_dofile(L, "script4.lua") == LUA_OK) {
        lua_pop(L, lua_gettop(L));
    }

    // Put the function to be called onto the stack
    lua_getglobal(L, "my_function");
    lua_pushinteger(L, 3);  // first argument
    lua_pushinteger(L, 4);  // second argument

    // Execute my_function with 2 arguments and 1 return value
    if (lua_pcall(L, 2, 1, 0) == LUA_OK) {

        // Check if the return is an integer
        if (lua_isinteger(L, -1)) {

            // Convert the return value to integer
            int result = lua_tointeger(L, -1);

            // Pop the return value
            lua_pop(L, 1);
            printf("Result: %d\n", result);
        }
        // Remove the function from the stack
        lua_pop(L, lua_gettop(L));
    }

    lua_close(L);
    return 0;
}
