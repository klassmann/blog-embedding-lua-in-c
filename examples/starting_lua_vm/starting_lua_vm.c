
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>

int main(int argc, char ** argv) {

    lua_State *l = luaL_newstate();
    luaL_openlibs(l);

    // Work with lua API

    lua_close(l);
    return 0;
}
