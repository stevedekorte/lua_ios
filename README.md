
lua_ios
======

lua_ios is C library which includes LuaJIT and lua bindings for:

	OpenGLES
	luasocket
	OpenAL

Example use:

	lua_State luaState = lua_open();
	luaopen_lua_ios(luaState);

	NSString *filePath = [[NSBundle mainBundle] 
		pathForResource:@"main" ofType:@"lua"];

    luaL_loadfile(_luaState, [filePath UTF8String]);
        
