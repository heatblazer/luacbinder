#include <stdio.h>

#include <lua.h>
#include <lualib.h>
#include <lualib.h>

#include <stdlib.h>

/* the Lua interpreter */
lua_State* L;



#if 0
int main ( int argc, char *argv[] )
{

    /* initialize Lua */
    L = luaL_newstate();

    /* load various Lua libraries */
    luaL_openlibs(L);
    luaopen_table(L);
    luaopen_io(L);
    luaopen_string(L);
    luaopen_math(L);

lua_register(
            L,               /* Lua state variable */
            "square",        /* func name as known in Lua */
            isquare          /* func name in this file */
            );
    lua_register(L,"cube",icube);

    /* cleanup Lua */
    lua_close(L);

    return 0;
}
#endif

static int getState1(lua_State* L)
{
    char* rtrn = lua_tostring(L, -1);      /* Get the single number arg */
    printf("Current state %s\n",rtrn);
    lua_pushstring(L,rtrn);           /* Push the return */
    return 1;
}


static int getState2(lua_State* L)
{
    char* rtrn = lua_tostring(L, -1);      /* Get the single number arg */
    printf("Current state %s\n",rtrn);
    lua_pushstring(L,rtrn);           /* Push the return */
    return 1;
}



int luaopen_appctx(lua_State *L){

    lua_register(L,"getState1",getState1);
    lua_register(L,"getState2",getState2);
    return 0;
}

