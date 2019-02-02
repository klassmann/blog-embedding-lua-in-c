
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>

int main(int argc, char ** argv) {

    lua_State *l = luaL_newstate();
    luaL_openlibs(l);

    char * code = "print('Hello, World')";
    
    if (luaL_loadstring(l, code) == LUA_OK) {
        if (lua_pcall(l, 0, 1, 0) == LUA_OK) {
            lua_pop(l, lua_gettop(l));
        }
    }

    lua_close(l);
    return 0;
}
