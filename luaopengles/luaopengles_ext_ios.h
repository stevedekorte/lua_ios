//
// open gl es docs: http://www.khronos.org/opengles/sdk/1.1/docs/man/
//
// an OpenGL ES iOS extensions binding for Lua by
// Steve Dekorte and Rich Collins
//
// See License_DekorteAndCollins.txt

#ifndef luaopengles_ext_ios_h
#define luaopengles_ext_ios_h

#include "lua.h"
#include "lauxlib.h"

LUALIB_API int luaopen_luaopengles_ext_ios(lua_State * L);

#endif