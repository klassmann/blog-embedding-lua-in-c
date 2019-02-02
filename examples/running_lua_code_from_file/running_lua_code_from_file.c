
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>

int main(int argc, char ** argv) {

    lua_State *L = luaL_newstate();
    luaL_openlibs(L);
    
    if (luaL_loadfile(L, "script.lua") == LUA_OK) {
        if (lua_pcall(L, 0, 1, 0) == LUA_OK) {
            lua_pop(L, lua_gettop(L));
        }
    }

    lua_close(L);
    return 0;
}
