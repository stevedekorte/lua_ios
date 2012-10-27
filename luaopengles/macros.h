
#if defined(__APPLE__) && defined(__MACH__)
	//#include <OpenGLES/EAGL.h>
	#include <OpenGLES/ES2/gl.h>
	#include <OpenGLES/ES2/glext.h>
#else
	#include <GL/gl.h>
	#include <GL/glext.h>
#endif


typedef double GLdouble;

static inline const char * check_string(lua_State *L, int n)
{
   if (lua_type(L,n) != LUA_TSTRING)
      luaL_typerror(L, n, lua_typename(L, LUA_TSTRING));
   return (const char *) lua_tostring(L, n);
}

static inline const void * check_lightuserdata(lua_State *L, int n)
{
   if (lua_type(L,n) != LUA_TLIGHTUSERDATA)
      luaL_typerror(L, n, "lightuserdata");
   return (const void *) lua_touserdata(L, n);
}

#define CONSTANT(name)\
   lua_pushstring(L, #name);\
   lua_pushnumber(L, name);\
   lua_settable(L, LUA_GLOBALSINDEX);

#define POINTER(name)\
   lua_pushstring(L, #name);\
   lua_pushlightuserdata(L, name);\
   lua_settable(L, LUA_GLOBALSINDEX);

#define FUN_SPEC(name)

#define FUN(name)\
   lua_register(L, #name, L ## name);

static inline GLboolean check_GLboolean(lua_State *L, int n)
{
   if (lua_type(L,n) != LUA_TNUMBER)
      luaL_typerror(L, n, "number(GLboolean)");
   return (GLboolean) lua_tonumber(L, n);
}

static inline GLbyte check_GLbyte(lua_State *L, int n)
{
   if (lua_type(L,n) != LUA_TNUMBER)
      luaL_typerror(L, n, "number(GLbyte)");
   return (GLbyte) lua_tonumber(L, n);
}

static inline GLubyte check_GLubyte(lua_State *L, int n)
{
   if (lua_type(L,n) != LUA_TNUMBER)
      luaL_typerror(L, n, "number(GLubyte)");
   return (GLubyte) lua_tonumber(L, n);
}

static inline GLshort check_GLshort(lua_State *L, int n)
{
   if (lua_type(L,n) != LUA_TNUMBER)
      luaL_typerror(L, n, "number(GLshort)");
   return (GLshort) lua_tonumber(L, n);
}

static inline GLushort check_GLushort(lua_State *L, int n)
{
   if (lua_type(L,n) != LUA_TNUMBER)
      luaL_typerror(L, n, "number(GLushort)");
   return (GLushort) lua_tonumber(L, n);
}

static inline GLint check_GLint(lua_State *L, int n)
{
   if (lua_type(L,n) != LUA_TNUMBER)
      luaL_typerror(L, n, "number(GLint)");
   return (GLint) lua_tonumber(L, n);
}

static inline GLuint check_GLuint(lua_State *L, int n)
{
   if (lua_type(L,n) != LUA_TNUMBER)
      luaL_typerror(L, n, "number(GLuint)");
   return (GLuint) lua_tonumber(L, n);
}

static inline GLsizei check_GLsizei(lua_State *L, int n)
{
   if (lua_type(L,n) != LUA_TNUMBER)
      luaL_typerror(L, n, "number(GLsizei)");
   return (GLsizei) lua_tonumber(L, n);
}

static inline GLenum check_GLenum(lua_State *L, int n)
{
   if (lua_type(L,n) != LUA_TNUMBER)
      luaL_typerror(L, n, "number(GLenum)");
   return (GLenum) lua_tonumber(L, n);
}

static inline GLbitfield check_GLbitfield(lua_State *L, int n)
{
   if (lua_type(L,n) != LUA_TNUMBER)
      luaL_typerror(L, n, "number(GLbitfield)");
   return (GLbitfield) lua_tonumber(L, n);
}

static inline GLfloat check_GLfloat(lua_State *L, int n)
{
   if (lua_type(L,n) != LUA_TNUMBER)
      luaL_typerror(L, n, "number(GLfloat)");
   return (GLfloat) lua_tonumber(L, n);
}

static inline GLdouble check_GLdouble(lua_State *L, int n)
{
   if (lua_type(L,n) != LUA_TNUMBER)
      luaL_typerror(L, n, "number(GLdouble)");
   return (GLdouble) lua_tonumber(L, n);
}

static inline int check_int(lua_State *L, int n)
{
   if (lua_type(L,n) != LUA_TNUMBER)
      luaL_typerror(L, n, "number(int)");
   return (int) lua_tonumber(L, n);
}

static inline unsigned int check_uint(lua_State *L, int n)
{
   if (lua_type(L,n) != LUA_TNUMBER)
      luaL_typerror(L, n, "number(unsigned int)");
   return (unsigned int) lua_tonumber(L, n);
}

static inline float check_float(lua_State *L, int n)
{
   if (lua_type(L,n) != LUA_TNUMBER)
      luaL_typerror(L, n, "number(float)");
   return (float) lua_tonumber(L, n);
}

static inline double check_double(lua_State *L, int n)
{
   if (lua_type(L,n) != LUA_TNUMBER)
      luaL_typerror(L, n, "number(double)");
   return (double) lua_tonumber(L, n);
}


#define FUN_BE(name)\
LUA_API int L ## name (lua_State *L) {\
   GLenum a1 = (GLenum) check_GLenum(L, 1);\
   lua_pushnumber(L, (GLboolean) name(a1));\
   return 1;\
}

#define FUN_BuI(name)\
LUA_API int L ## name (lua_State *L) {\
   GLuint a1 = (GLuint) check_GLuint(L, 1);\
   lua_pushnumber(L, (GLboolean) name(a1));\
   return 1;\
}

#define FUN_E(name)\
LUA_API int L ## name (lua_State *L) {\
   lua_pushnumber(L, (GLenum) name());\
   return 1;\
}

#define FUN_IE(name)\
LUA_API int L ## name (lua_State *L) {\
   GLenum a1 = (GLenum) check_GLenum(L, 1);\
   lua_pushnumber(L, (GLint) name(a1));\
   return 1;\
}

#define FUN_sE(name)\
LUA_API int L ## name (lua_State *L) {\
   GLenum a1 = (GLenum) check_GLenum(L, 1);\
   lua_pushstring(L, (const char *) name(a1));\
   return 1;\
}

#define FUN_uIZ(name)\
LUA_API int L ## name (lua_State *L) {\
   GLsizei a1 = (GLsizei) check_GLsizei(L, 1);\
   lua_pushnumber(L, (GLuint) name(a1));\
   return 1;\
}

#define FUN_v(name)\
LUA_API int L ## name (lua_State *L) {\
   (void) L; /* unused */ \
   name();\
   return 0;\
}

#define FUN_vB(name)\
LUA_API int L ## name (lua_State *L) {\
   GLboolean a1 = (GLboolean) check_GLboolean(L, 1);\
   name(a1);\
   return 0;\
}

#define FUN_vB4(name)\
LUA_API int L ## name (lua_State *L) {\
   GLboolean a1 = (GLboolean) check_GLboolean(L, 1);\
   GLboolean a2 = (GLboolean) check_GLboolean(L, 2);\
   GLboolean a3 = (GLboolean) check_GLboolean(L, 3);\
   GLboolean a4 = (GLboolean) check_GLboolean(L, 4);\
   name(a1, a2, a3, a4);\
   return 0;\
}

#define FUN_vD(name)\
LUA_API int L ## name (lua_State *L) {\
   GLdouble a1 = (GLdouble) check_GLdouble(L, 1);\
   name(a1);\
   return 0;\
}

#define FUN_vD2(name)\
LUA_API int L ## name (lua_State *L) {\
   GLdouble a1 = (GLdouble) check_GLdouble(L, 1);\
   GLdouble a2 = (GLdouble) check_GLdouble(L, 2);\
   name(a1, a2);\
   return 0;\
}

#define FUN_vD3(name)\
LUA_API int L ## name (lua_State *L) {\
   GLdouble a1 = (GLdouble) check_GLdouble(L, 1);\
   GLdouble a2 = (GLdouble) check_GLdouble(L, 2);\
   GLdouble a3 = (GLdouble) check_GLdouble(L, 3);\
   name(a1, a2, a3);\
   return 0;\
}

#define FUN_vD4(name)\
LUA_API int L ## name (lua_State *L) {\
   GLdouble a1 = (GLdouble) check_GLdouble(L, 1);\
   GLdouble a2 = (GLdouble) check_GLdouble(L, 2);\
   GLdouble a3 = (GLdouble) check_GLdouble(L, 3);\
   GLdouble a4 = (GLdouble) check_GLdouble(L, 4);\
   name(a1, a2, a3, a4);\
   return 0;\
}

#define FUN_vD6(name)\
LUA_API int L ## name (lua_State *L) {\
   GLdouble a1 = (GLdouble) check_GLdouble(L, 1);\
   GLdouble a2 = (GLdouble) check_GLdouble(L, 2);\
   GLdouble a3 = (GLdouble) check_GLdouble(L, 3);\
   GLdouble a4 = (GLdouble) check_GLdouble(L, 4);\
   GLdouble a5 = (GLdouble) check_GLdouble(L, 5);\
   GLdouble a6 = (GLdouble) check_GLdouble(L, 6);\
   name(a1, a2, a3, a4, a5, a6);\
   return 0;\
}

#define FUN_vE(name)\
LUA_API int L ## name (lua_State *L) {\
   GLenum a1 = (GLenum) check_GLenum(L, 1);\
   name(a1);\
   return 0;\
}

#define FUN_vE2i(name)\
LUA_API int L ## name (lua_State *L) {\
   GLenum a1 = (GLenum) check_GLenum(L, 1);\
   GLenum a2 = (GLenum) check_GLenum(L, 2);\
   GLenum a3 = (GLenum) check_GLint(L, 3);\
   name(a1, a2, a3);\
   return 0;\
}

#define FUN_vE2iu(name)\
LUA_API int L ## name (lua_State *L) {\
   GLenum a1 = (GLenum) check_GLenum(L, 1);\
   GLenum a2 = (GLenum) check_GLenum(L, 2);\
   GLenum a3 = (GLenum) check_GLint(L, 3);\
   GLenum a4 = (GLenum) check_GLuint(L, 4);\
   name(a1, a2, a3, a4);\
   return 0;\
}

#define FUN_vv(name)\
LUA_API int L ## name (lua_State *L) {\
   name();\
   return 0;\
}

#define FUN_vE2(name)\
LUA_API int L ## name (lua_State *L) {\
   GLenum a1 = (GLenum) check_GLenum(L, 1);\
   GLenum a2 = (GLenum) check_GLenum(L, 2);\
   name(a1, a2);\
   return 0;\
}

#define FUN_vE2D(name)\
LUA_API int L ## name (lua_State *L) {\
   GLenum a1 = (GLenum) check_GLenum(L, 1);\
   GLenum a2 = (GLenum) check_GLenum(L, 2);\
   GLdouble a3 = (GLdouble) check_GLdouble(L, 3);\
   name(a1, a2, a3);\
   return 0;\
}

#define FUN_vE2F(name)\
LUA_API int L ## name (lua_State *L) {\
   GLenum a1 = (GLenum) check_GLenum(L, 1);\
   GLenum a2 = (GLenum) check_GLenum(L, 2);\
   GLfloat a3 = (GLfloat) check_GLfloat(L, 3);\
   name(a1, a2, a3);\
   return 0;\
}


#define FUN_vuEF(name)\
LUA_API int L ## name (lua_State *L) {\
   unsigned int a1 = (GLuint) check_GLuint(L, 1);\
   GLenum a2 = (GLenum) check_GLenum(L, 2);\
   GLfloat a3 = (GLfloat) check_GLfloat(L, 3);\
   name(a1, a2, a3);\
   return 0;\
}

#define FUN_vE2p(name)\
LUA_API int L ## name (lua_State *L) {\
   GLenum a1 = (GLenum) check_GLenum(L, 1);\
   GLenum a2 = (GLenum) check_GLenum(L, 2);\
   void * a3 = (void *) check_lightuserdata(L, 3);\
   name(a1, a2, a3);\
   return 0;\
}

#define FUN_vE3(name)\
LUA_API int L ## name (lua_State *L) {\
   GLenum a1 = (GLenum) check_GLenum(L, 1);\
   GLenum a2 = (GLenum) check_GLenum(L, 2);\
   GLenum a3 = (GLenum) check_GLenum(L, 3);\
   name(a1, a2, a3);\
   return 0;\
}

#define FUN_vE4(name)\
LUA_API int L ## name (lua_State *L) {\
   GLenum a1 = (GLenum) check_GLenum(L, 1);\
   GLenum a2 = (GLenum) check_GLenum(L, 2);\
   GLenum a3 = (GLenum) check_GLenum(L, 3);\
   GLenum a4 = (GLenum) check_GLenum(L, 4);\
   name(a1, a2, a3, a4);\
   return 0;\
}

#define FUN_vEF(name)\
LUA_API int L ## name (lua_State *L) {\
   GLenum a1 = (GLenum) check_GLenum(L, 1);\
   GLfloat a2 = (GLfloat) check_GLfloat(L, 2);\
   name(a1, a2);\
   return 0;\
}

#define FUN_vEI(name)\
LUA_API int L ## name (lua_State *L) {\
   GLenum a1 = (GLenum) check_GLenum(L, 1);\
   GLint a2 = (GLint) check_GLint(L, 2);\
   name(a1, a2);\
   return 0;\
}

#define FUN_vEIZ(name)\
LUA_API int L ## name (lua_State *L) {\
GLenum a1 = (GLenum) check_GLenum(L, 1);\
GLint a2 = (GLint) check_GLint(L, 2);\
GLint a3 = (GLsizei) check_GLsizei(L, 3);\
name(a1, a2, a3);\
return 0;\
}

#define FUN_vEI2Z2IE2p(name)\
LUA_API int L ## name (lua_State *L) {\
   GLenum a1 = (GLenum) check_GLenum(L, 1);\
   GLint a2 = (GLint) check_GLint(L, 2);\
   GLint a3 = (GLint) check_GLint(L, 3);\
   GLsizei a4 = (GLsizei) check_GLsizei(L, 4);\
   GLsizei a5 = (GLsizei) check_GLsizei(L, 5);\
   GLint a6 = (GLint) check_GLint(L, 6);\
   GLenum a7 = (GLenum) check_GLenum(L, 7);\
   GLenum a8 = (GLenum) check_GLenum(L, 8);\
   void * a9 = (void *) check_lightuserdata(L, 9);\
   name(a1, a2, a3, a4, a5, a6, a7, a8, a9);\
   return 0;\
}


#define FUN_vuZbP(name)\
LUA_API int L ## name (lua_State *L) {\
	GLuint a1     = (GLuint) check_GLint(L, 1);\
	GLsizei a2       = (GLint) check_GLsizei(L, 2);\
	GLboolean a3 = (GLenum) check_GLboolean(L, 3);\
	memarray_t *memarray = (void *) lua_touserdata(L, 4);\
	const GLfloat *a4 = ((GLfloat *)(memarray->data));\
	glUniformMatrix4fv(a1, a2, a3, a4);\
	return 0;\
}


#define FUN_vEI2ZIE2p(name)\
LUA_API int L ## name (lua_State *L) {\
   GLenum a1 = (GLenum) check_GLenum(L, 1);\
   GLint a2 = (GLint) check_GLint(L, 2);\
   GLint a3 = (GLint) check_GLint(L, 3);\
   GLsizei a4 = (GLsizei) check_GLsizei(L, 4);\
   GLint a5 = (GLint) check_GLint(L, 5);\
   GLenum a6 = (GLenum) check_GLenum(L, 6);\
   GLenum a7 = (GLenum) check_GLenum(L, 7);\
   void * a8 = (void *) check_lightuserdata(L, 8);\
   name(a1, a2, a3, a4, a5, a6, a7, a8);\
   return 0;\
}

#define FUN_vEIE2p(name)\
LUA_API int L ## name (lua_State *L) {\
   GLenum a1 = (GLenum) check_GLenum(L, 1);\
   GLint a2 = (GLint) check_GLint(L, 2);\
   GLenum a3 = (GLenum) check_GLenum(L, 3);\
   GLenum a4 = (GLenum) check_GLenum(L, 4);\
   void * a5 = (void *) check_lightuserdata(L, 5);\
   name(a1, a2, a3, a4, a5);\
   return 0;\
}

#define FUN_vEIEp(name)\
LUA_API int L ## name (lua_State *L) {\
   GLenum a1 = (GLenum) check_GLenum(L, 1);\
   GLint a2 = (GLint) check_GLint(L, 2);\
   GLenum a3 = (GLenum) check_GLenum(L, 3);\
   void * a4 = (void *) check_lightuserdata(L, 4);\
   name(a1, a2, a3, a4);\
   return 0;\
}

#define FUN_vEIp(name)\
LUA_API int L ## name (lua_State *L) {\
   GLenum a1 = (GLenum) check_GLenum(L, 1);\
   GLint a2 = (GLint) check_GLint(L, 2);\
   void * a3 = (void *) check_lightuserdata(L, 3);\
   name(a1, a2, a3);\
   return 0;\
}

#define FUN_vEIuI(name)\
LUA_API int L ## name (lua_State *L) {\
   GLenum a1 = (GLenum) check_GLenum(L, 1);\
   GLint a2 = (GLint) check_GLint(L, 2);\
   GLuint a3 = (GLuint) check_GLuint(L, 3);\
   name(a1, a2, a3);\
   return 0;\
}

#define FUN_vEp(name)\
LUA_API int L ## name (lua_State *L) {\
   GLenum a1 = (GLenum) check_GLenum(L, 1);\
   void * a2 = (void *) check_lightuserdata(L, 2);\
   name(a1, a2);\
   return 0;\
}

#define FUN_vEu(name)\
LUA_API int L ## name (lua_State *L) {\
   GLenum a1 = (GLenum) check_GLenum(L, 1);\
   GLuint a2 = (GLuint) check_GLuint(L, 2);\
   name(a1, a2);\
   return 0;\
}

#define FUN_vE(name)\
LUA_API int L ## name (lua_State *L) {\
   GLenum a1 = (GLenum) check_GLenum(L, 1);\
   name(a1);\
   return 0;\
}

#define FUN_uv(name)\
LUA_API int L ## name (lua_State *L) {\
   lua_pushnumber(L, (GLfloat) name());\
   return 1;\
}

#define FUN_uE(name)\
LUA_API int L ## name (lua_State *L) {\
 	GLenum a1 = (GLenum) check_GLenum(L, 1);\
  lua_pushnumber(L, (GLuint) name(a1));\
   return 1;\
}




#define FUN_vEuI(name)\
LUA_API int L ## name (lua_State *L) {\
	GLenum a1 = (GLenum) check_GLenum(L, 1);\
	GLuint a2 = (GLuint) check_GLuint(L, 2);\
	GLint a3 = (GLint) check_GLint(L, 3);\
	name(a1, a2, a3);\
	return 0;\
}

#define FUN_vF(name)\
LUA_API int L ## name (lua_State *L) {\
   GLfloat a1 = (GLfloat) check_GLfloat(L, 1);\
   name(a1);\
   return 0;\
}

#define FUN_vF2(name)\
LUA_API int L ## name (lua_State *L) {\
   GLfloat a1 = (GLfloat) check_GLfloat(L, 1);\
   GLfloat a2 = (GLfloat) check_GLfloat(L, 2);\
   name(a1, a2);\
   return 0;\
}

#define FUN_vF3(name)\
LUA_API int L ## name (lua_State *L) {\
GLfloat a1 = (GLfloat) check_GLfloat(L, 1);\
GLfloat a2 = (GLfloat) check_GLfloat(L, 2);\
GLfloat a3 = (GLfloat) check_GLfloat(L, 3);\
name(a1, a2, a3);\
return 0;\
}

#define FUN_vF4(name)\
LUA_API int L ## name (lua_State *L) {\
   GLfloat a1 = (GLfloat) check_GLfloat(L, 1);\
   GLfloat a2 = (GLfloat) check_GLfloat(L, 2);\
   GLfloat a3 = (GLfloat) check_GLfloat(L, 3);\
   GLfloat a4 = (GLfloat) check_GLfloat(L, 4);\
   name(a1, a2, a3, a4);\
   return 0;\
}

#define FUN_vF5(name)\
LUA_API int L ## name (lua_State *L) {\
GLfloat a1 = (GLfloat) check_GLfloat(L, 1);\
GLfloat a2 = (GLfloat) check_GLfloat(L, 2);\
GLfloat a3 = (GLfloat) check_GLfloat(L, 3);\
GLfloat a4 = (GLfloat) check_GLfloat(L, 4);\
GLfloat a5 = (GLfloat) check_GLfloat(L, 5);\
name(a1, a2, a3, a4, a5);\
return 0;\
}

#define FUN_vF6(name)\
LUA_API int L ## name (lua_State *L) {\
GLfloat a1 = (GLfloat) check_GLfloat(L, 1);\
GLfloat a2 = (GLfloat) check_GLfloat(L, 2);\
GLfloat a3 = (GLfloat) check_GLfloat(L, 3);\
GLfloat a4 = (GLfloat) check_GLfloat(L, 4);\
GLfloat a5 = (GLfloat) check_GLfloat(L, 5);\
GLfloat a6 = (GLfloat) check_GLfloat(L, 6);\
name(a1, a2, a3, a4, a5, a6);\
return 0;\
}


#define FUN_vI(name)\
LUA_API int L ## name (lua_State *L) {\
   GLint a1 = (GLint) check_GLint(L, 1);\
   name(a1);\
   return 0;\
}

#define FUN_vI2Z2(name)\
LUA_API int L ## name (lua_State *L) {\
   GLint a1 = (GLint) check_GLint(L, 1);\
   GLint a2 = (GLint) check_GLint(L, 2);\
   GLsizei a3 = (GLsizei) check_GLsizei(L, 3);\
   GLsizei a4 = (GLsizei) check_GLsizei(L, 4);\
   name(a1, a2, a3, a4);\
   return 0;\
}

#define FUN_vI2Z2E(name)\
LUA_API int L ## name (lua_State *L) {\
   GLint a1 = (GLint) check_GLint(L, 1);\
   GLint a2 = (GLint) check_GLint(L, 2);\
   GLsizei a3 = (GLsizei) check_GLsizei(L, 3);\
   GLsizei a4 = (GLsizei) check_GLsizei(L, 4);\
   GLenum a5 = (GLenum) check_GLenum(L, 5);\
   name(a1, a2, a3, a4, a5);\
   return 0;\
}

#define FUN_vI2Z2E2p(name)\
LUA_API int L ## name (lua_State *L) {\
   GLint a1 = (GLint) check_GLint(L, 1);\
   GLint a2 = (GLint) check_GLint(L, 2);\
   GLsizei a3 = (GLsizei) check_GLsizei(L, 3);\
   GLsizei a4 = (GLsizei) check_GLsizei(L, 4);\
   GLenum a5 = (GLenum) check_GLenum(L, 5);\
   GLenum a6 = (GLenum) check_GLenum(L, 6);\
   void * a7 = (void *) check_lightuserdata(L, 7);\
   name(a1, a2, a3, a4, a5, a6, a7);\
   return 0;\
}

#define FUN_vIuH(name)\
LUA_API int L ## name (lua_State *L) {\
   GLint a1 = (GLint) check_GLint(L, 1);\
   GLushort a2 = (GLushort) check_GLushort(L, 2);\
   name(a1, a2);\
   return 0;\
}

#define FUN_vp(name)\
LUA_API int L ## name (lua_State *L) {\
   void * a1 = (void *) check_lightuserdata(L, 1);\
   name(a1);\
   return 0;\
}

#define FUN_vT(name)\
LUA_API int L ## name (lua_State *L) {\
   GLbitfield a1 = (GLbitfield) check_GLbitfield(L, 1);\
   name(a1);\
   return 0;\
}

#define FUN_vuI(name)\
LUA_API int L ## name (lua_State *L) {\
   GLuint a1 = (GLuint) check_GLuint(L, 1);\
   name(a1);\
   return 0;\
}

#define FUN_vuIE(name)\
LUA_API int L ## name (lua_State *L) {\
   GLuint a1 = (GLuint) check_GLuint(L, 1);\
   GLenum a2 = (GLenum) check_GLenum(L, 2);\
   name(a1, a2);\
   return 0;\
}

#define FUN_vuIZ(name)\
LUA_API int L ## name (lua_State *L) {\
   GLuint a1 = (GLuint) check_GLuint(L, 1);\
   GLsizei a2 = (GLsizei) check_GLsizei(L, 2);\
   name(a1, a2);\
   return 0;\
}

#define FUN_vZ2E2p(name)\
LUA_API int L ## name (lua_State *L) {\
   GLsizei a1 = (GLsizei) check_GLsizei(L, 1);\
   GLsizei a2 = (GLsizei) check_GLsizei(L, 2);\
   GLenum a3 = (GLenum) check_GLenum(L, 3);\
   GLenum a4 = (GLenum) check_GLenum(L, 4);\
   void * a5 = (void *) check_lightuserdata(L, 5);\
   name(a1, a2, a3, a4, a5);\
   return 0;\
}

#define FUN_vZ2F4p(name)\
LUA_API int L ## name (lua_State *L) {\
   GLsizei a1 = (GLsizei) check_GLsizei(L, 1);\
   GLsizei a2 = (GLsizei) check_GLsizei(L, 2);\
   GLfloat a3 = (GLfloat) check_GLfloat(L, 3);\
   GLfloat a4 = (GLfloat) check_GLfloat(L, 4);\
   GLfloat a5 = (GLfloat) check_GLfloat(L, 5);\
   GLfloat a6 = (GLfloat) check_GLfloat(L, 6);\
   void * a7 = (void *) check_lightuserdata(L, 7);\
   name(a1, a2, a3, a4, a5, a6, a7);\
   return 0;\
}

#define FUN_vZEp(name)\
LUA_API int L ## name (lua_State *L) {\
   GLsizei a1 = (GLsizei) check_GLsizei(L, 1);\
   GLenum a2 = (GLenum) check_GLenum(L, 2);\
   void * a3 = (void *) check_lightuserdata(L, 3);\
   name(a1, a2, a3);\
   return 0;\
}

#define FUN_vZp(name)\
LUA_API int L ## name (lua_State *L) {\
   GLsizei a1 = (GLsizei) check_GLsizei(L, 1);\
   void * a2 = (void *) check_lightuserdata(L, 2);\
   name(a1, a2);\
   return 0;\
}

#define FUN_Fi2(name)\
LUA_API int L ## name (lua_State *L) {\
   int a1 = (int) check_int(L, 1);\
   int a2 = (int) check_int(L, 2);\
   lua_pushnumber(L, (GLfloat) name(a1, a2));\
   return 1;\
}

#define FUN_i(name)\
LUA_API int L ## name (lua_State *L) {\
   lua_pushnumber(L, (int) name());\
   return 1;\
}

#define FUN_iD3p6(name)\
LUA_API int L ## name (lua_State *L) {\
   GLdouble a1 = (GLdouble) check_GLdouble(L, 1);\
   GLdouble a2 = (GLdouble) check_GLdouble(L, 2);\
   GLdouble a3 = (GLdouble) check_GLdouble(L, 3);\
   void * a4 = (void *) check_lightuserdata(L, 4);\
   void * a5 = (void *) check_lightuserdata(L, 5);\
   void * a6 = (void *) check_lightuserdata(L, 6);\
   void * a7 = (void *) check_lightuserdata(L, 7);\
   void * a8 = (void *) check_lightuserdata(L, 8);\
   void * a9 = (void *) check_lightuserdata(L, 9);\
   lua_pushnumber(L, (int) name(a1, a2, a3, a4, a5, a6, a7, a8, a9));\
   return 1;\
}

#define FUN_iE(name)\
LUA_API int L ## name (lua_State *L) {\
   GLenum a1 = (GLenum) check_GLenum(L, 1);\
   lua_pushnumber(L, (int) name(a1));\
   return 1;\
}

#define FUN_IEIZ2E2p(name)\
LUA_API int L ## name (lua_State *L) {\
   GLenum a1 = (GLenum) check_GLenum(L, 1);\
   GLint a2 = (GLint) check_GLint(L, 2);\
   GLsizei a3 = (GLsizei) check_GLsizei(L, 3);\
   GLsizei a4 = (GLsizei) check_GLsizei(L, 4);\
   GLenum a5 = (GLenum) check_GLenum(L, 5);\
   GLenum a6 = (GLenum) check_GLenum(L, 6);\
   void * a7 = (void *) check_lightuserdata(L, 7);\
   lua_pushnumber(L, (GLint) name(a1, a2, a3, a4, a5, a6, a7));\
   return 0;\
}

#define FUN_vIEZp(name)\
LUA_API int L ## name (lua_State *L) {\
GLint a1 = (GLint) check_GLint(L, 1);\
GLenum a2 = (GLenum) check_GLenum(L, 2);\
GLsizei a3 = (GLsizei) check_GLsizei(L, 3);\
void *a4 = (void *) check_lightuserdata(L, 4);\
name(a1, a2, a3, a4);\
return 1;\
}

#define FUN_IEIZE2p(name)\
LUA_API int L ## name (lua_State *L) {\
   GLenum a1 = (GLenum) check_GLenum(L, 1);\
   GLint a2 = (GLint) check_GLint(L, 2);\
   GLsizei a3 = (GLsizei) check_GLsizei(L, 3);\
   GLenum a4 = (GLenum) check_GLenum(L, 4);\
   GLenum a5 = (GLenum) check_GLenum(L, 5);\
   void * a6 = (void *) check_lightuserdata(L, 6);\
   lua_pushnumber(L, (GLint) name(a1, a2, a3, a4, a5, a6));\
   return 1;\
}

#define FUN_ip(name)\
LUA_API int L ## name (lua_State *L) {\
   void * a1 = (void *) check_lightuserdata(L, 1);\
   lua_pushnumber(L, (int) name(a1));\
   return 1;\
}

#define FUN_ipi(name)\
LUA_API int L ## name (lua_State *L) {\
   void * a1 = (void *) check_lightuserdata(L, 1);\
   int a2 = (int) check_int(L, 2);\
   lua_pushnumber(L, (int) name(a1, a2));\
   return 1;\
}


#define FUN_is(name)\
LUA_API int L ## name (lua_State *L) {\
   const char * a1 = (const char *) check_string(L, 1);\
   lua_pushnumber(L, (int) name(a1));\
   return 1;\
}

#define FUN_iIs(name)\
LUA_API int L ## name (lua_State *L) {\
   GLint a1 = (GLint) check_GLint(L, 1);\
   const char * a2 = (const char *) check_string(L, 2);\
   lua_pushnumber(L, (int) name(a1, a2));\
   return 1;\
}

#define FUN_vIIs(name)\
LUA_API int L ## name (lua_State *L) {\
   GLint a1 = (GLint) check_GLint(L, 1);\
   GLint a2 = (GLint) check_GLint(L, 2);\
   const char * a3 = (const char *) check_string(L, 3);\
   name(a1, a2, a3);\
   return 1;\
}


#define FUN_ius(name)\
LUA_API int L ## name (lua_State *L) {\
   GLuint a1 = (GLuint) check_GLuint(L, 1);\
   const char * a2 = (const char *) check_string(L, 2);\
   lua_pushnumber(L, (int) name(a1, a2));\
   return 1;\
}

#define FUN_vuus(name)\
LUA_API int L ## name (lua_State *L) {\
   GLuint a1 = (GLuint) check_GLuint(L, 1);\
   GLuint a2 = (GLuint) check_GLuint(L, 2);\
   const char * a3 = (const char *) check_string(L, 3);\
   name(a1, a2, a3);\
   return 1;\
}

#define FUN_vu(name)\
LUA_API int L ## name (lua_State *L) {\
   GLuint a1 = (GLuint) check_GLuint(L, 1);\
   name(a1);\
   return 1;\
}

#define FUN_uu(name)\
LUA_API int L ## name (lua_State *L) {\
   GLuint a1 = (GLuint) check_GLuint(L, 1);\
   lua_pushnumber(L, (int) name(a1));\
   return 1;\
}


#define FUN_vuu(name)\
LUA_API int L ## name (lua_State *L) {\
   GLuint a1 = (GLuint) check_GLuint(L, 1);\
   GLuint a2 = (GLuint) check_GLuint(L, 2);\
   name(a1, a2);\
   return 1;\
}


#define FUN_p(name)\
LUA_API int L ## name (lua_State *L) {\
   lua_pushlightuserdata(L, (void *) name());\
   return 1;\
}

#define FUN_ps(name)\
LUA_API int L ## name (lua_State *L) {\
   const char * a1 = (const char *) check_string(L, 1);\
   lua_pushlightuserdata(L, (void *) name(a1));\
   return 1;\
}

#define FUN_v(name)\
LUA_API int L ## name (lua_State *L) {\
   (void) L; /* unused */ \
   name();\
   return 0;\
}

#define FUN_vD(name)\
LUA_API int L ## name (lua_State *L) {\
   GLdouble a1 = (GLdouble) check_GLdouble(L, 1);\
   name(a1);\
   return 0;\
}

#define FUN_vD2I2(name)\
LUA_API int L ## name (lua_State *L) {\
   GLdouble a1 = (GLdouble) check_GLdouble(L, 1);\
   GLdouble a2 = (GLdouble) check_GLdouble(L, 2);\
   GLint a3 = (GLint) check_GLint(L, 3);\
   GLint a4 = (GLint) check_GLint(L, 4);\
   name(a1, a2, a3, a4);\
   return 0;\
}

#define FUN_vD4(name)\
LUA_API int L ## name (lua_State *L) {\
   GLdouble a1 = (GLdouble) check_GLdouble(L, 1);\
   GLdouble a2 = (GLdouble) check_GLdouble(L, 2);\
   GLdouble a3 = (GLdouble) check_GLdouble(L, 3);\
   GLdouble a4 = (GLdouble) check_GLdouble(L, 4);\
   name(a1, a2, a3, a4);\
   return 0;\
}

#define FUN_vD4p(name)\
LUA_API int L ## name (lua_State *L) {\
   GLdouble a1 = (GLdouble) check_GLdouble(L, 1);\
   GLdouble a2 = (GLdouble) check_GLdouble(L, 2);\
   GLdouble a3 = (GLdouble) check_GLdouble(L, 3);\
   GLdouble a4 = (GLdouble) check_GLdouble(L, 4);\
   void * a5 = (void *) check_lightuserdata(L, 5);\
   name(a1, a2, a3, a4, a5);\
   return 0;\
}

#define FUN_vD9(name)\
LUA_API int L ## name (lua_State *L) {\
   GLdouble a1 = (GLdouble) check_GLdouble(L, 1);\
   GLdouble a2 = (GLdouble) check_GLdouble(L, 2);\
   GLdouble a3 = (GLdouble) check_GLdouble(L, 3);\
   GLdouble a4 = (GLdouble) check_GLdouble(L, 4);\
   GLdouble a5 = (GLdouble) check_GLdouble(L, 5);\
   GLdouble a6 = (GLdouble) check_GLdouble(L, 6);\
   GLdouble a7 = (GLdouble) check_GLdouble(L, 7);\
   GLdouble a8 = (GLdouble) check_GLdouble(L, 8);\
   GLdouble a9 = (GLdouble) check_GLdouble(L, 9);\
   name(a1, a2, a3, a4, a5, a6, a7, a8, a9);\
   return 0;\
}

#define FUN_vDI2(name)\
LUA_API int L ## name (lua_State *L) {\
   GLdouble a1 = (GLdouble) check_GLdouble(L, 1);\
   GLint a2 = (GLint) check_GLint(L, 2);\
   GLint a3 = (GLint) check_GLint(L, 3);\
   name(a1, a2, a3);\
   return 0;\
}

#define FUN_vE(name)\
LUA_API int L ## name (lua_State *L) {\
   GLenum a1 = (GLenum) check_GLenum(L, 1);\
   name(a1);\
   return 0;\
}

#define FUN_vi(name)\
LUA_API int L ## name (lua_State *L) {\
   int a1 = (int) check_int(L, 1);\
   name(a1);\
   return 0;\
}

#define FUN_vI(name)\
LUA_API int L ## name (lua_State *L) {\
   GLint a1 = (GLint) check_GLint(L, 1);\
   name(a1);\
   return 0;\
}

#define FUN_vi2(name)\
LUA_API int L ## name (lua_State *L) {\
   int a1 = (int) check_int(L, 1);\
   int a2 = (int) check_int(L, 2);\
   name(a1, a2);\
   return 0;\
}


#define FUN_vi3(name)\
LUA_API int L ## name (lua_State *L) {\
   int a1 = (int) check_int(L, 1);\
   int a2 = (int) check_int(L, 2);\
   int a3 = (int) check_int(L, 3);\
   name(a1, a2, a3);\
   return 0;\
}

#define FUN_vi4(name)\
LUA_API int L ## name (lua_State *L) {\
   int a1 = (int) check_int(L, 1);\
   int a2 = (int) check_int(L, 2);\
   int a3 = (int) check_int(L, 3);\
   int a4 = (int) check_int(L, 4);\
   name(a1, a2, a3, a4);\
   return 0;\
}

#define FUN_vi5(name)\
LUA_API int L ## name (lua_State *L) {\
   int a1 = (int) check_int(L, 1);\
   int a2 = (int) check_int(L, 2);\
   int a3 = (int) check_int(L, 3);\
   int a4 = (int) check_int(L, 4);\
   int a5 = (int) check_int(L, 5);\
   name(a1, a2, a3, a4, a5);\
   return 0;\
}


#define FUN_viF(name)\
LUA_API int L ## name (lua_State *L) {\
   int a1 = (int) check_int(L, 1);\
   GLfloat a2 = (GLfloat) check_GLfloat(L, 2);\
   name(a1, a2);\
   return 0;\
}

#define FUN_viFF(name)\
LUA_API int L ## name (lua_State *L) {\
   int a1 = (int) check_int(L, 1);\
   GLfloat a2 = (GLfloat) check_GLfloat(L, 2);\
   GLfloat a3 = (GLfloat) check_GLfloat(L, 3);\
   name(a1, a2, a3);\
   return 0;\
}

#define FUN_viFFF(name)\
LUA_API int L ## name (lua_State *L) {\
   int a1 = (int) check_int(L, 1);\
   GLfloat a2 = (GLfloat) check_GLfloat(L, 2);\
   GLfloat a3 = (GLfloat) check_GLfloat(L, 3);\
   GLfloat a4 = (GLfloat) check_GLfloat(L, 4);\
   name(a1, a2, a3, a4);\
   return 0;\
}

#define FUN_viFFFF(name)\
LUA_API int L ## name (lua_State *L) {\
   int a1 = (int) check_int(L, 1);\
   GLfloat a2 = (GLfloat) check_GLfloat(L, 2);\
   GLfloat a3 = (GLfloat) check_GLfloat(L, 3);\
   GLfloat a4 = (GLfloat) check_GLfloat(L, 4);\
   GLfloat a5 = (GLfloat) check_GLfloat(L, 5);\
   name(a1, a2, a3, a4, a5);\
   return 0;\
}

#define FUN_visi(name)\
LUA_API int L ## name (lua_State *L) {\
   int a1 = (int) check_int(L, 1);\
   const char * a2 = (const char *) check_string(L, 2);\
   int a3 = (int) check_int(L, 3);\
   name(a1, a2, a3);\
   return 0;\
}

#define FUN_vp(name)\
LUA_API int L ## name (lua_State *L) {\
   void * a1 = (void *) check_lightuserdata(L, 1);\
   name(a1);\
   return 0;\
}

#define FUN_vpi(name)\
LUA_API int L ## name (lua_State *L) {\
   void * a1 = (void *) check_lightuserdata(L, 1);\
   int a2 = (int) check_int(L, 2);\
   name(a1, a2);\
   return 0;\
}

#define FUN_vps(name)\
LUA_API int L ## name (lua_State *L) {\
   void * a1 = (void *) check_lightuserdata(L, 1);\
   const char * a2 = (const char *) check_string(L, 2);\
   name(a1, a2);\
   return 0;\
}

#define FUN_vs(name)\
LUA_API int L ## name (lua_State *L) {\
   const char * a1 = (const char *) check_string(L, 1);\
   name(a1);\
   return 0;\
}

#define FUN_vsi(name)\
LUA_API int L ## name (lua_State *L) {\
   const char * a1 = (const char *) check_string(L, 1);\
   int a2 = (int) check_int(L, 2);\
   name(a1, a2);\
   return 0;\
}

#define FUN_vui(name)\
LUA_API int L ## name (lua_State *L) {\
   unsigned int a1 = (unsigned int) check_uint(L, 1);\
   name(a1);\
   return 0;\
}
