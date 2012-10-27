
lua_ios
======

lua_ios is a lightweight MIT licensed lua game engine alternative to frameworks like Corona or Moai. It includes LuaJIT and bindings for:

	OpenGLES
	luasocket
	OpenAL

USAGE

To use, just include the lua_ios folder in your Xcode project, add your own main.lua resource file and call the following in your GLESView:

	lua_State luaState = lua_open();
	luaopen_lua_ios(luaState);

	NSString *filePath = [[NSBundle mainBundle] 
		pathForResource:@"main" ofType:@"lua"];

    luaL_loadfile(_luaState, [filePath UTF8String]);
 
AUTHORS

Steve Dekorte and Rich Collins
        
