
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>

int main(int argc, char ** argv) {

    lua_State *L = luaL_newstate();
    luaL_openlibs(L);

    char * code = "print(return)"; // intentional error

    if (luaL_dostring(L, code) != LUA_OK) {
        puts(lua_tostring(L, lua_gettop(L)));
        lua_pop(L, lua_gettop(L));
    }

    lua_close(L);
    return 0;
}
