#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>

int main(int argc, char ** argv) {

    lua_State *l = luaL_newstate();
    luaL_openlibs(l);

    if (luaL_loadfile(l, "script2.lua") == LUA_OK) {
        if (lua_pcall(l, 0, 1, 0) == LUA_OK) {
            lua_pop(l, lua_gettop(l));
        }
    }

    lua_getglobal(l, "message");

    if (lua_isstring(l, -1)) {
        const char * message = lua_tostring(l, -1);
        lua_pop(l, 1);
        printf("Message from lua: %s\n", message);
    }

    lua_close(l);
    return 0;
}
