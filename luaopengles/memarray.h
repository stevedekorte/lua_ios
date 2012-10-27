
#ifndef memarray_h
#define memarray_h

#include <stdlib.h>
#include "lua.h"
#include "lauxlib.h"

typedef struct memarray
{
   size_t   size;
   size_t   length;
   unsigned int flags;
   void     *data;
} memarray_t;


LUALIB_API int luaopen_memarray(lua_State * L);

#endif