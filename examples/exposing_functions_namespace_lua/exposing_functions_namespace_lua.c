#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>

// Here is the same function from the previous example
int multiplication(lua_State *l) {
    int a = luaL_checkinteger(l, 1);
    int b = luaL_checkinteger(l, 2);
    lua_Integer c = a * b;
    lua_pushinteger(l, c);
    return 1;
}

int main(int argc, char ** argv) {

    lua_State *l = luaL_newstate();
    luaL_openlibs(l);

    // First we need to define an array with
    // all functions that will be available inside our namespace 
    static const struct luaL_Reg MyMathLib[] = {
        { "mul", multiplication }
    };

    // We create a new table
    lua_newtable(l);

    // Here we set all functions from MyMathLib array into
    // the table on the top of the stack
    luaL_setfuncs(l, MyMathLib, 0);

    // We get the table and set as global variable
    lua_setglobal(l, "MyMath");
    
    // Now we can call from Lua using the namespace MyMath
    char * code = "print(MyMath.mul(7, 8))";

    if (luaL_loadstring(l, code) == LUA_OK) {
        if (lua_pcall(l, 0, 1, 0) == LUA_OK) {
            lua_pop(l, lua_gettop(l));
        }
    }

    lua_close(l);
    return 0;
}
