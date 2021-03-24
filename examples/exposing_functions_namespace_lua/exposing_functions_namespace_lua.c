#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>

// Here is the same function from the previous example
int multiplication(lua_State *L) {
    int a = luaL_checkinteger(L, 1);
    int b = luaL_checkinteger(L, 2);
    lua_Integer c = a * b;
    lua_pushinteger(L, c);
    return 1;
}

int main(int argc, char ** argv) {

    lua_State *L = luaL_newstate();
    luaL_openlibs(L);

    // First we need to define an array with
    // all functions that will be available inside our namespace 
    const struct luaL_Reg MyMathLib[] = {
        { "mul", multiplication }
    };

    // We create a new table
    lua_newtable(L);

    // Here we set all functions from MyMathLib array into
    // the table on the top of the stack
    luaL_setfuncs(L, &MyMathLib, 0);

    // We get the table and set as global variable
    lua_setglobal(L, "MyMath");
    
    // Now we can call from Lua using the namespace MyMath
    char * code = "print(MyMath.mul(7, 8))";

    if (luaL_dostring(L, code) == LUA_OK) {
        lua_pop(L, lua_gettop(L));
    }

    lua_close(L);
    return 0;
}
