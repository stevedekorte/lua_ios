//
// By Steve Dekorte and Rich Collins
// 

#include "lua_ios.h"

#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"

#include "luaopengles.h"
#include "luasocket.h"
#include "luaopenal.h"

	
LUALIB_API int luaopen_lua_ios(lua_State * L)
{
	luaL_openlibs(L);
	luaopen_luagleslibs(L);
	luaopen_socket_core(L);
	luaopen_luaopenal(L);
	return 1;
}
