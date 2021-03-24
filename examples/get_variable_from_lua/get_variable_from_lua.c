#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>

int main(int argc, char ** argv) {

    lua_State *L = luaL_newstate();
    luaL_openlibs(L);

    if (luaL_dofile(L, "script2.lua") == LUA_OK) {
        lua_pop(L, lua_gettop(L));
    }

    lua_getglobal(L, "message");

    if (lua_isstring(L, -1)) {
        const char * message = lua_tostring(L, -1);
        lua_pop(L, 1);
        printf("Message from lua: %s\n", message);
    }

    lua_close(L);
    return 0;
}
