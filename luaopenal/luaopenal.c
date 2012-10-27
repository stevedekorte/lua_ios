#include <stdio.h>
#include <string.h>
#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"

//#include <OpenAL/al.h>
//#include <OpenAL/alc.h>

#if defined(__APPLE__) && defined(__MACH__)
	#include <OpenAL/al.h>
	#include <OpenAL/alc.h>
#else
	#include <al/al.h>
	#include <al/alc.h>
#endif

#include "memarray.h"
#include <stdio.h>
#include "lua.h"
#include "lauxlib.h"
#include "macros.h"

// AL BINDINGS

LUA_API int LalGenBuffer(lua_State * L) // alGenBuffers
{
	ALuint ids[1];
	alGenBuffers(1, ids);     
	lua_pushnumber(L, ids[0]);
	return 1;
}

LUA_API int LalDeleteBuffer(lua_State * L) // alDeleteBuffers
{
	ALuint a1 = (ALuint) check_GLuint(L, 1);
	ALuint ids[1];
	ids[0] = a1;
	alDeleteBuffers(1, ids);
	return 0;
}

LUA_API int LalGenSource(lua_State * L) // alGenSources
{
	ALuint ids[1];
	alGenSources(1, ids);     
	lua_pushnumber(L, ids[0]);
	return 1;
}

LUA_API int LalDeleteSource(lua_State * L) // alDeleteSources
{
	ALuint a1 = (ALuint) check_uint(L, 1);
	ALuint ids[1];
	ids[0] = a1;
	alDeleteSources(1, ids);
	return 0;
}

FUN_vu(alSourcePlay)
FUN_vu(alSourceStop)
FUN_vu(alSourceRewind)
FUN_vu(alSourcePause)

// source

LUA_API int LalSourcef(lua_State * L) // alSourcef
{
	ALuint a1 = (ALuint) check_uint(L, 1);
	ALenum a2 = (ALenum) check_GLenum(L, 2);
	float a3 = (float) check_float(L, 3);
	alSourcef(a1, a2, a3);
	return 0;
}

LUA_API int LalSource3f(lua_State * L) // alSource3f
{
	ALuint a1 = (ALuint) check_uint(L, 1);
	ALenum a2 = (GLenum) check_GLenum(L, 2);
	float a3 = (float) check_float(L, 3);
	float a4 = (float) check_float(L, 4);
	float a5 = (float) check_float(L, 5);
	alSource3f(a1, a2, a3, a4, a5);
	return 0;
}

// listener

LUA_API int LalListenerf(lua_State * L) 
{
	ALenum a1 = (ALenum) check_GLenum(L, 1);
	float a2 = (float) check_float(L, 2);
	alListenerf(a1, a2);
	return 0;
}

LUA_API int LalListener3f(lua_State * L) 
{
	ALenum a1 = (ALenum) check_GLenum(L, 1);
	float a2 = (float) check_float(L, 2);
	float a3 = (float) check_float(L, 3);
	float a4 = (float) check_float(L, 4);
	alListener3f(a1, a2, a3, a4);
	return 0;
}

FUN_E(alGetError)
FUN_sE(alGetString)

LUA_API int LalGetSourcei(lua_State * L) 
{
	ALuint a1 = (ALuint) check_uint(L, 1);
	ALenum a2 = (ALenum) check_GLenum(L, 2);
	ALint v1;
	alGetSourcei(a1, a2, &v1);
	lua_pushnumber(L, v1);
	return 1;
}

LUA_API int LalGetSource3i(lua_State * L) 
{
	ALuint a1 = (ALuint) check_uint(L, 1);
	ALenum a2 = (ALenum) check_GLenum(L, 2);
	ALint v1, v2, v3;
	alGetSource3i(a1, a2, &v1, &v2, &v3);
	lua_pushnumber(L, v1);
	lua_pushnumber(L, v2);
	lua_pushnumber(L, v3);
	return 3;
}

// ALC BINDINGS


LUA_API int LalcOpenDevice(lua_State * L)
{
	const char *s = (const char *) check_string(L, 1);
	
	if (strlen(s) == 0)
	{
		s = NULL;
	}
	
	ALCdevice *device = alcOpenDevice(s);
	lua_pushlightuserdata(L, device);
	return 1;
}


LUA_API int LalcGetString(lua_State * L)
{
	ALCdevice *device = (void *) check_lightuserdata(L, 1);
	ALCenum param = (ALCenum) check_GLenum(L, 2);
	const ALCchar *s = alcGetString(device, param);
	lua_pushstring(L, s);
	return 1;
}

LUA_API int LalcCreateContext(lua_State * L)
{
	ALCdevice *device = (void *) check_lightuserdata(L, 1);
	//ALCint attrlist[10];
	ALCcontext *context = alcCreateContext(device, NULL);
	lua_pushlightuserdata(L, context);
	return 1;
}

FUN_ip(alcMakeContextCurrent)


LUA_API int LalcGetError(lua_State * L) 
{
	ALCdevice *device = (void *) check_lightuserdata(L, 1);
	ALCenum r = alcGetError(device);
	lua_pushnumber(L, r);
	return 1;
}

FUN_p(alcGetCurrentContext)

LUA_API int LalcGetContextsDevice(lua_State * L) 
{
	ALCcontext *context = (void *) check_lightuserdata(L, 1);
	ALCdevice *device = alcGetContextsDevice(context);
	lua_pushlightuserdata(L, device);
	return 1;
}

FUN_vp(alcDestroyContext)
FUN_ip(alcCloseDevice)


void register_openal(lua_State *L)
{
	// AL BINDINGS
	CONSTANT(AL_NO_ERROR)
	CONSTANT(AL_FALSE)
	CONSTANT(AL_TRUE)
	CONSTANT(AL_BUFFER)
	CONSTANT(AL_PITCH)
	CONSTANT(AL_GAIN)
	CONSTANT(AL_POSITION)
	CONSTANT(AL_VELOCITY)
	CONSTANT(AL_ORIENTATION)
	CONSTANT(AL_LOOPING)
	CONSTANT(AL_PLAYING)
	CONSTANT(AL_SOURCE_STATE)

	FUN(alGenBuffer)
	FUN(alDeleteBuffer)
	FUN(alGenSource)
	FUN(alDeleteSource)

	//FUN(alBufferData)

	//FUN(alSourcei)
	FUN(alSourcef)
	FUN(alSource3f)

	FUN(alSourcePlay)
	FUN(alSourceStop)
	FUN(alSourcePause)

	FUN(alListenerf)
	FUN(alListener3f)

	FUN(alGetError)
	FUN(alGetString)
	FUN(alGetSourcei)

	// ALUT BINDINGS
	//FUN(alutInit)
	//FUN(alutExit)
	//FUN(alutLoadWAVFile)
	//FUN(alutUnloadWAV)

	// ALC BINDINGS
	CONSTANT(ALC_NO_ERROR)
	CONSTANT(ALC_DEVICE_SPECIFIER)
	FUN(alcOpenDevice)
	FUN(alcGetString)
	FUN(alcCreateContext)
	FUN(alcMakeContextCurrent)
	FUN(alcGetError)
	FUN(alcGetCurrentContext)
	FUN(alcGetContextsDevice)
	FUN(alcDestroyContext)
	FUN(alcCloseDevice)
}


#define MYNAME "luaopenal"
#define VERSION "0.1"

LUALIB_API int luaopen_luaopenal(lua_State * L)
{
   register_openal(L);

   lua_newtable(L);

   lua_pushstring(L, "VERSION");
   lua_pushstring(L, VERSION);
   lua_settable(L, -3);

   lua_pushstring(L, MYNAME);
   lua_pushvalue(L, -2);
   lua_settable(L, LUA_GLOBALSINDEX);

   return 1;
}
