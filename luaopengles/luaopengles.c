//
// an OpenGL ES binding for Lua by
// Steve Dekorte and Rich Collins
//
// based on the OpenGL binding by  Varol Kaptan
// Copyright (C) 2005-2006 Varol Kaptan
//
// OpenGL ES API docs: http://www.khronos.org/opengles/sdk/1.1/docs/man/
//


#include "memarray.h"
#include <stdio.h>
#include "lua.h"
#include "lauxlib.h"
#include "macros.h"

#if defined(__APPLE__) && defined(__MACH__)
	//#include <OpenGLES/EAGL.h>
	#include <OpenGLES/ES2/gl.h>
	#include <OpenGLES/ES2/glext.h>
#else
	#include <GL/gl.h>
	#include <GL/glext.h>
#endif




FUN_vE(glActiveTexture)
FUN_vuu(glAttachShader)

FUN_vuus(glBindAttribLocation)
FUN_vEI(glBindBuffer)
//FUN_vEu(glBindFramebuffer)
//FUN_vEu(glBindRenderbuffer)
FUN_vi2(glBindTexture)
//FUN_vFFFF(glBlendColor)
FUN_vE(glBlendEquation)
//FUN_vEE(glBlendEquationSeparate)
FUN_vE2(glBlendFunc)

LUA_API int LglBufferData(lua_State * L)
{
	GLenum arg1 = (GLenum) check_GLint(L, 1);
	GLuint size = (GLuint) check_GLint(L, 2);

	if (lua_type(L, 3) != LUA_TUSERDATA)
	{
		luaL_error(L, "LglBufferData argument 3: lightuserdata required\n");
	}
	
	memarray_t *memarray = (void *) lua_touserdata(L, 3);
	
	GLuint arg4 = (GLuint) check_GLint(L, 4);
    glBufferData(arg1, size, memarray->data, arg4);
	return 0;
}

LUA_API int LglBufferSubData(lua_State * L)
{
	GLenum target = (GLenum) check_GLint(L, 1);
	GLintptr offset = (GLintptr) check_GLuint(L, 1);
	GLuint size = (GLuint) check_GLint(L, 3);

	if (lua_type(L, 4) != LUA_TUSERDATA)
	{
		luaL_error(L, "LglBufferSubData argument 4: lightuserdata required\n");
	}
	
	memarray_t *memarray = (void *) lua_touserdata(L, 4);
	
    glBufferSubData(target, offset, size, memarray->data);
	return 0;
}

FUN_vE(glCheckFramebufferStatus)
FUN_vT(glClear)
FUN_vF4(glClearColor)
FUN_vF(glClearDepthf)
FUN_vI(glClearStencil) 
FUN_vB4(glColorMask)
FUN_vu(glCompileShader)
FUN_vE(glCullFace)
//FUN_(glCompressedTexImage2D)
//FUN_(glCompressedTexSubImage2D)
//FUN_(glCopyTexImage2D)
//FUN_(glCopyTexSubImage2D)
FUN_uv(glCreateProgram)
FUN_uE(glCreateShader)

LUA_API int LglDeleteBuffer(lua_State * L) //glDeleteBuffers
{	
	GLuint ids[1];
	ids[0] = (GLuint) check_GLint(L, 1);
    glDeleteBuffers(1, (const GLuint *)&ids);
	return 0;
}

LUA_API int LglDeleteFramebuffer(lua_State * L) //glDeleteFramebuffers
{	
	GLuint ids[1];
	ids[0] = (GLuint) check_GLint(L, 1);
    glDeleteFramebuffers(1, (const GLuint *)&ids);
	return 0;
}

FUN_vu(glDeleteProgram)

LUA_API int LglDeleteTexture(lua_State * L) //glDeleteTextures
{	
	GLuint ids[1];
	ids[0] = (GLuint) check_GLint(L, 1);
    glDeleteTextures(1, (const GLuint *)&ids);
	return 0;
}

//glDeleteRenderbuffers
LUA_API int LglDeleteRenderbuffer(lua_State * L)
{	
	GLuint ids[1];
	ids[0] = (GLuint) check_GLint(L, 1);
    glDeleteRenderbuffers(1, (const GLuint *)&ids);
	return 0;
}

FUN_vu(glDeleteShader)
FUN_vuu(glDetachShader)
FUN_vE(glDepthFunc)
FUN_vu(glDepthMask)

void glDepthRangef(	GLclampf nearVal, GLclampf farVal);
FUN_vF2(glDepthRangef)
FUN_vE(glDisable)
FUN_vu(glDisableVertexAttribArray)
FUN_vEIZ(glDrawArrays)
//glDrawBuffer
//FUN_vEIZ(glDrawElements)
FUN_vE(glEnable)

void glEnableVertexAttribArray(GLuint index);

LUA_API int LglEnableVertexAttribArray(lua_State * L)
{
	GLenum arg1 = (GLenum) check_GLint(L, 1);
    glEnableVertexAttribArray(arg1);
	return 0;
}

FUN_v(glFinish)
FUN_v(glFlush)  
//FUN_iEEEu(glFramebufferRenderbuffer)
//FUN_vEEEuI(glFramebufferTexture2D)
//FUN_vE(glFrontFace)

FUN_ius(glGetAttribLocation)

FUN_vEp(glGetBooleanv)

LUA_API int LglGenBuffer(lua_State * L) //glGenBuffers
{
	GLint arg1 = (GLint) check_GLint(L, 1);
	GLuint id = 0;
    glGenBuffers(arg1, &id);
	lua_pushnumber(L, id);
	return 1;
}

//FUN_vE(glGenerateMipmap)

LUA_API int LglGenFramebuffer(lua_State * L) //glGenFramebuffers
{
	GLint arg1 = (GLint) check_GLint(L, 1);
	GLuint id = 0;
    glGenFramebuffers(arg1, &id);
	lua_pushnumber(L, id);
	return 1;
}

LUA_API int LglGenRenderbuffer(lua_State * L) //glGenRenderbuffers
{
	GLint arg1 = (GLint) check_GLint(L, 1);
	GLuint id = 0;
    glGenRenderbuffers(arg1, &id);
	lua_pushnumber(L, id);
	return 1;
}

LUA_API int LglGenTexture(lua_State * L) //glGenTextures
{
	GLint arg1 = (GLint) check_GLint(L, 1);
	GLuint id = 0;
    glGenTextures(arg1, &id);
	lua_pushnumber(L, id);
	return 1;
}

/*
void glGetActiveAttrib(GLuint program,
 	GLuint  	index,
 	GLsizei  	bufSize,
 	GLsizei * 	length,
 	GLint * 	size,
 	GLenum * 	type,
 	GLchar * 	name);
	
void glGetActiveUniform(GLuint program,
 	GLuint  	index,
 	GLsizei  	bufSize,
 	GLsizei * 	length,
 	GLint * 	size,
 	GLenum * 	type,
 	GLchar * 	name);

void glGetAttachedShaders(GLuint program,
 	GLsizei  	maxCount,
 	GLsizei * 	count,
 	GLuint * 	shaders);	
*/




//void glGetBufferParameteriv(GLenum target, GLenum value, GLint *data)
LUA_API int LglGetBufferParameteriv(lua_State * L)
{
	GLenum a1 = (GLint) check_GLenum(L, 1);
	GLenum a2 = (GLint) check_GLenum(L, 2);
	GLint id = 0;
    glGetBufferParameteriv(a1, a2, &id);
	lua_pushnumber(L, id);
	return 1;
}

FUN_E(glGetError)
FUN_vEp(glGetFloatv)

LUA_API int LglGetFramebufferAttachmentParameteriv(lua_State * L)
{
	GLenum a1 = (GLint) check_GLenum(L, 1);
	GLenum a2 = (GLint) check_GLenum(L, 2);
	GLenum a3 = (GLint) check_GLenum(L, 3);
	GLint id = 0;
    glGetFramebufferAttachmentParameteriv(a1, a2, a3, &id);
	lua_pushnumber(L, id);
	return 1;
}

FUN_vEp(glGetIntegerv) // glGetIntegerv(GLenum pname, GLint *params);

/*
 void glGetProgramInfoLog(	GLuint  	program,
 	GLsizei  	maxLength,
 	GLsizei * 	length,
 	GLchar * 	infoLog);
*/

LUA_API int LglGetProgramiv(lua_State * L) //glGenBuffers
{
	GLuint a1 = (GLuint) check_GLuint(L, 1);
	GLenum a2 = (GLenum) check_GLenum(L, 2);
	GLint id = 0;
    glGetProgramiv(a1, a2, &id);
	lua_pushnumber(L, id);
	return 1;
}

LUA_API int LglGetRenderbufferParameteriv(lua_State * L) // glGetRenderbufferParameteriv
{
	GLenum a1 = (GLenum) check_GLenum(L, 1);
	GLenum a2 = (GLenum) check_GLenum(L, 2);
	GLint id = 0;
    glGetRenderbufferParameteriv(a1, a2, &id);
	lua_pushnumber(L, id);
	return 1;
}

LUA_API int LglGetShaderiv(lua_State * L) // glGetRenderbufferParameteriv
{
	GLuint a1 = (GLuint) check_GLuint(L, 1);
	GLenum a2 = (GLenum) check_GLenum(L, 2);
	GLint id = 0;
    glGetShaderiv(a1, a2, &id);
	lua_pushnumber(L, id);
	return 1;
}

/*

void glGetShaderInfoLog(	GLuint  	shader,
 	GLsizei  	maxLength,
 	GLsizei * 	length,
 	GLchar * 	infoLog);


void glGetShaderPrecisionFormat(	GLenum shaderType,
 	GLenum precisionType,
 	GLint *range,
 	GLint *precision);
 */


LUA_API int LglGetShaderSource(lua_State * L) // glGetRenderbufferParameteriv
{
	GLuint shader = (GLuint) check_GLuint(L, 1);
	GLsizei bufSize = (GLsizei) check_GLsizei(L, 1);
	GLsizei length;
	GLchar *source = calloc(1, bufSize);
    glGetShaderSource(shader, bufSize, &length, source);
	lua_pushnumber(L, length);
	lua_pushstring(L, source);
	free(source);
	return 2;
}

FUN_sE(glGetString)
FUN_vE2p(glGetTexParameterfv)
FUN_ius(glGetUniformLocation)

FUN_vE2(glHint)

FUN_uu(glIsBuffer)
FUN_BE(glIsEnabled) 
FUN_uu(glIsFramebuffer)
FUN_uu(glIsProgram)
FUN_uu(glIsRenderbuffer)
FUN_uu(glIsShader)
FUN_uu(glIsTexture)

FUN_vF(glLineWidth)
FUN_vu(glLinkProgram)

FUN_vEI(glPixelStorei)
FUN_vF2(glPolygonOffset)

FUN_vI2Z2E2p(glReadPixels)
FUN_vv(glReleaseShaderCompiler)
//FUN_vE2Z2(glRenderbufferStorage)

//FUN_vu(glSampleCoverage) // 2nd arg is actually boolean
FUN_vI2Z2(glScissor)

/*
void glShaderBinary(GLsizei n,
 	const GLuint *shaders,
 	GLenum binaryformat,
 	const void *binary,
 	GLsizei length);

void glShaderSource(GLuint shader,
 	GLsizei count,
 	const GLchar **string,
 	const GLint *length);
*/


FUN_vEIuI(glStencilFunc)  
FUN_vE2iu(glStencilFuncSeparate)
FUN_vu(glStencilMask)
FUN_vEu(glStencilMaskSeparate)
FUN_vE3(glStencilOp)
FUN_vE4(glStencilOpSeparate)

FUN_vEI2Z2IE2p(glTexImage2D)
FUN_vE2F(glTexParameterf)

FUN_vE2i(glTexParameteri)
//glTexParameteriv

//glTexSubImage2D
/*
void glGetTexParameteriv(	GLenum  	target,
 	GLenum  	pname,
 	GLint *  	params);




void glGetUniformfv(GLuint program,
 	GLint location,
 	GLfloat *params);
void glGetUniformiv(GLuint program,
 	GLint location,
 	GLint *params);
*/

//FUN_Ius(glGetUniformLocation)

/*
void glGetVertexAttribdv(	GLuint  	index,
 	GLenum  	pname,
 	GLdouble * 	params);
void glGetVertexAttribfv(GLuint  	index,
 	GLenum  	pname,
 	GLfloat * 	params);
void glGetVertexAttribiv(GLuint index, GLenum pname, GLint * 	params);



oid glGetVertexAttribPointerv(	GLuint  	index,
 	GLenum  	pname,
 	GLvoid ** 	pointer);
*/

FUN_viF(glUniform1f)
//FUN_viFF(glUniform2f)
FUN_viFFF(glUniform3f)
FUN_viFFFF(glUniform4f)

FUN_vi2(glUniform1i)
FUN_vi3(glUniform2i)
FUN_vi4(glUniform3i)
FUN_vi5(glUniform4i)
//FUN_(glUniform1fv)
//FUN_(glUniform1iv)
//FUN_(glUniform2fv)
//FUN_(glUniform2iv)
//FUN_(glUniform3fv)
//FUN_(glUniform3iv)
//FUN_(glUniform4fv)
//FUN_(glUniform4iv)
FUN_vuZbP(glUniformMatrix3fv)
FUN_vuZbP(glUniformMatrix4fv)
FUN_vu(glUseProgram)

FUN_vu(glValidateProgram)
FUN_viF(glVertexAttrib1f)
FUN_viFF(glVertexAttrib2f)
FUN_viFFF(glVertexAttrib3f)
FUN_viFFFF(glVertexAttrib4f)
//FUN_(glVertexAttrib1fv)
//FUN_(glVertexAttrib2fv)
//FUN_(glVertexAttrib3fv)
//FUN_(glVertexAttrib4fv)
FUN_vI2Z2(glViewport)

LUA_API int LglVertexAttribPointer(lua_State * L)
{
	GLuint index = (GLuint) check_GLint(L, 1);
	GLint size = (GLint) check_GLint(L, 2);
	GLenum type = (GLenum) check_GLint(L, 3);
	GLboolean normalized = (GLboolean) check_GLint(L, 4);
	GLsizei stride = (GLsizei) check_GLint(L, 5);
	
	//GLint offset = (GLint) check_GLint(L, 6);
    //glVertexAttribPointer(index, size, type, normalized, stride, (const GLvoid *)offset);

	memarray_t *memarray = (void *) lua_touserdata(L, 6);
	const GLvoid *pointer = ((u_int8_t *)(memarray->data));		
    glVertexAttribPointer(index, size, type, normalized, stride, pointer);
	
	return 0;
}




void register_gl(lua_State *L)
{
	CONSTANT(GL_ACTIVE_ATTRIBUTES)
	CONSTANT(GL_ACTIVE_ATTRIBUTE_MAX_LENGTH)
	CONSTANT(GL_ACTIVE_TEXTURE)
	CONSTANT(GL_ACTIVE_UNIFORMS)
	CONSTANT(GL_ACTIVE_UNIFORM_MAX_LENGTH)
	CONSTANT(GL_ALIASED_LINE_WIDTH_RANGE)
	CONSTANT(GL_ALIASED_POINT_SIZE_RANGE)
	CONSTANT(GL_ALPHA)
	CONSTANT(GL_ALPHA_BITS)
	CONSTANT(GL_ALWAYS)
	CONSTANT(GL_ARRAY_BUFFER)
	CONSTANT(GL_ATTACHED_SHADERS)
	CONSTANT(GL_BACK)
	CONSTANT(GL_BGRA_EXT)
	CONSTANT(GL_BLEND)
	CONSTANT(GL_BLEND_COLOR)
	CONSTANT(GL_BLEND_EQUATION)
	CONSTANT(GL_BLUE_BITS)
	//CONSTANT(GL_BUFFER_ACCESS)
	//CONSTANT(GL_BUFFER_MAPPED)
	CONSTANT(GL_BUFFER_SIZE)
	CONSTANT(GL_BUFFER_USAGE)
	CONSTANT(GL_BYTE)
	CONSTANT(GL_CCW)
	CONSTANT(GL_CLAMP_TO_EDGE)
	CONSTANT(GL_COLOR_BUFFER_BIT)
	CONSTANT(GL_COLOR_CLEAR_VALUE)
	CONSTANT(GL_COLOR_WRITEMASK)
	CONSTANT(GL_COMPILE_STATUS)
	CONSTANT(GL_COMPRESSED_TEXTURE_FORMATS)
	CONSTANT(GL_CULL_FACE)
	CONSTANT(GL_CULL_FACE_MODE)
	CONSTANT(GL_CURRENT_VERTEX_ATTRIB)
	CONSTANT(GL_CW)
	CONSTANT(GL_DECR)
	CONSTANT(GL_DELETE_STATUS)
	CONSTANT(GL_DELETE_STATUS)
	CONSTANT(GL_DEPTH_BITS)
	CONSTANT(GL_DEPTH_BUFFER_BIT)
	CONSTANT(GL_DEPTH_CLEAR_VALUE)
	CONSTANT(GL_DEPTH_FUNC)
	CONSTANT(GL_DEPTH_RANGE)
	CONSTANT(GL_DEPTH_TEST)
	//CONSTANT(GL_DEPTH_TEXTURE_MODE)
	CONSTANT(GL_DEPTH_WRITEMASK)
	CONSTANT(GL_DITHER)
	CONSTANT(GL_DONT_CARE)
	CONSTANT(GL_DST_ALPHA)
	CONSTANT(GL_DST_COLOR)
	CONSTANT(GL_DYNAMIC_DRAW)
	CONSTANT(GL_EQUAL)
	CONSTANT(GL_EXTENSIONS)
	CONSTANT(GL_FALSE)
	CONSTANT(GL_FASTEST)
	CONSTANT(GL_FLOAT)
	CONSTANT(GL_FRAGMENT_SHADER)
	CONSTANT(GL_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME)
	CONSTANT(GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE)
	CONSTANT(GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE)
	CONSTANT(GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL)
	CONSTANT(GL_FRONT)
	CONSTANT(GL_FRONT_AND_BACK)
	CONSTANT(GL_FRONT_FACE)
	CONSTANT(GL_FUNC_ADD)
	CONSTANT(GL_FUNC_REVERSE_SUBTRACT)
	CONSTANT(GL_FUNC_SUBTRACT)
	//CONSTANT(GL_GENERATE_MIPMAP)
	CONSTANT(GL_GEQUAL)
	CONSTANT(GL_GREATER)
	CONSTANT(GL_GREEN_BITS)
	CONSTANT(GL_INCR)
	CONSTANT(GL_INFO_LOG_LENGTH)
	CONSTANT(GL_INFO_LOG_LENGTH)
	CONSTANT(GL_INVALID_ENUM)
	CONSTANT(GL_INVALID_OPERATION)
	CONSTANT(GL_INVALID_VALUE)
	CONSTANT(GL_KEEP)
	CONSTANT(GL_LEQUAL)
	CONSTANT(GL_LESS)
	CONSTANT(GL_LINEAR)
	CONSTANT(GL_LINEAR_MIPMAP_LINEAR)
	CONSTANT(GL_LINEAR_MIPMAP_NEAREST)
	CONSTANT(GL_LINES)
	CONSTANT(GL_LINE_LOOP)
	CONSTANT(GL_LINE_STRIP)
	CONSTANT(GL_LINE_WIDTH)
	CONSTANT(GL_LINK_STATUS)
	CONSTANT(GL_LUMINANCE)
	CONSTANT(GL_LUMINANCE_ALPHA)
	CONSTANT(GL_MAX_CUBE_MAP_TEXTURE_SIZE)
	CONSTANT(GL_MAX_TEXTURE_SIZE)
	CONSTANT(GL_MAX_VIEWPORT_DIMS)
	CONSTANT(GL_NEAREST)
	CONSTANT(GL_NEAREST_MIPMAP_LINEAR)
	CONSTANT(GL_NEAREST_MIPMAP_NEAREST)
	CONSTANT(GL_NEVER)
	CONSTANT(GL_NICEST)
	CONSTANT(GL_NOTEQUAL)
	CONSTANT(GL_NO_ERROR)
	CONSTANT(GL_NUM_COMPRESSED_TEXTURE_FORMATS)
	CONSTANT(GL_ONE)
	CONSTANT(GL_ONE_MINUS_DST_ALPHA)
	CONSTANT(GL_ONE_MINUS_DST_COLOR)
	CONSTANT(GL_ONE_MINUS_SRC_ALPHA)
	CONSTANT(GL_ONE_MINUS_SRC_COLOR)
	CONSTANT(GL_OUT_OF_MEMORY)
	CONSTANT(GL_PACK_ALIGNMENT)
	CONSTANT(GL_POINTS)
	CONSTANT(GL_POLYGON_OFFSET_FACTOR)
	CONSTANT(GL_POLYGON_OFFSET_FILL)
	CONSTANT(GL_POLYGON_OFFSET_UNITS)
	CONSTANT(GL_RED_BITS)
	CONSTANT(GL_RENDERBUFFER_ALPHA_SIZE)
	CONSTANT(GL_RENDERBUFFER_BLUE_SIZE)
	CONSTANT(GL_RENDERBUFFER_DEPTH_SIZE)
	CONSTANT(GL_RENDERBUFFER_GREEN_SIZE)
	CONSTANT(GL_RENDERBUFFER_HEIGHT)
	CONSTANT(GL_RENDERBUFFER_INTERNAL_FORMAT)
	CONSTANT(GL_RENDERBUFFER_RED_SIZE)
	CONSTANT(GL_RENDERBUFFER_STENCIL_SIZE)
	CONSTANT(GL_RENDERBUFFER_WIDTH)
	CONSTANT(GL_RENDERER)
	CONSTANT(GL_REPEAT)
	CONSTANT(GL_REPLACE)
	CONSTANT(GL_RGB)
	CONSTANT(GL_RGB5_A1)
	CONSTANT(GL_RGBA)
	CONSTANT(GL_RGBA4)
	CONSTANT(GL_SAMPLES)
	CONSTANT(GL_SAMPLE_ALPHA_TO_COVERAGE)
	CONSTANT(GL_SAMPLE_BUFFERS)
	CONSTANT(GL_SAMPLE_COVERAGE)
	CONSTANT(GL_SAMPLE_COVERAGE_INVERT)
	CONSTANT(GL_SAMPLE_COVERAGE_VALUE)
	CONSTANT(GL_SCISSOR_BOX)
	CONSTANT(GL_SCISSOR_TEST)
	CONSTANT(GL_SHADER_SOURCE_LENGTH)
	CONSTANT(GL_SHADER_TYPE)
	CONSTANT(GL_SHORT)
	CONSTANT(GL_SRC_ALPHA)
	CONSTANT(GL_SRC_ALPHA_SATURATE)
	CONSTANT(GL_SRC_COLOR)
	CONSTANT(GL_STATIC_DRAW)
	CONSTANT(GL_STENCIL_BITS)
	CONSTANT(GL_STENCIL_BUFFER_BIT)
	CONSTANT(GL_STENCIL_CLEAR_VALUE)
	CONSTANT(GL_STENCIL_FAIL)
	CONSTANT(GL_STENCIL_FUNC)
	CONSTANT(GL_STENCIL_PASS_DEPTH_FAIL)
	CONSTANT(GL_STENCIL_PASS_DEPTH_PASS)
	CONSTANT(GL_STENCIL_REF)
	CONSTANT(GL_STENCIL_TEST)
	CONSTANT(GL_STENCIL_VALUE_MASK)
	CONSTANT(GL_STENCIL_WRITEMASK)
	CONSTANT(GL_SUBPIXEL_BITS)
	CONSTANT(GL_TEXTURE)
	CONSTANT(GL_TEXTURE0)
	CONSTANT(GL_TEXTURE1)
	CONSTANT(GL_TEXTURE10)
	CONSTANT(GL_TEXTURE11)
	CONSTANT(GL_TEXTURE12)
	CONSTANT(GL_TEXTURE13)
	CONSTANT(GL_TEXTURE14)
	CONSTANT(GL_TEXTURE15)
	CONSTANT(GL_TEXTURE16)
	CONSTANT(GL_TEXTURE17)
	CONSTANT(GL_TEXTURE18)
	CONSTANT(GL_TEXTURE19)
	CONSTANT(GL_TEXTURE2)
	CONSTANT(GL_TEXTURE20)
	CONSTANT(GL_TEXTURE21)
	CONSTANT(GL_TEXTURE22)
	CONSTANT(GL_TEXTURE23)
	CONSTANT(GL_TEXTURE24)
	CONSTANT(GL_TEXTURE25)
	CONSTANT(GL_TEXTURE26)
	CONSTANT(GL_TEXTURE27)
	CONSTANT(GL_TEXTURE28)
	CONSTANT(GL_TEXTURE29)
	CONSTANT(GL_TEXTURE3)
	CONSTANT(GL_TEXTURE30)
	CONSTANT(GL_TEXTURE31)
	CONSTANT(GL_TEXTURE4)
	CONSTANT(GL_TEXTURE5)
	CONSTANT(GL_TEXTURE6)
	CONSTANT(GL_TEXTURE7)
	CONSTANT(GL_TEXTURE8)
	CONSTANT(GL_TEXTURE9)
	CONSTANT(GL_TEXTURE_2D)
	//CONSTANT(GL_TEXTURE_BASE_LEVEL)
	CONSTANT(GL_TEXTURE_BINDING_2D)
	CONSTANT(GL_TEXTURE_BINDING_CUBE_MAP)
	//CONSTANT(GL_TEXTURE_BORDER_COLOR)
	//CONSTANT(GL_TEXTURE_COMPARE_FUNC)
	//CONSTANT(GL_TEXTURE_COMPARE_MODE)
	CONSTANT(GL_TEXTURE_CUBE_MAP)
	CONSTANT(GL_TEXTURE_CUBE_MAP_NEGATIVE_X)
	CONSTANT(GL_TEXTURE_CUBE_MAP_NEGATIVE_Y)
	CONSTANT(GL_TEXTURE_CUBE_MAP_NEGATIVE_Z)
	CONSTANT(GL_TEXTURE_CUBE_MAP_POSITIVE_X)
	CONSTANT(GL_TEXTURE_CUBE_MAP_POSITIVE_Y)
	CONSTANT(GL_TEXTURE_CUBE_MAP_POSITIVE_Z)
	CONSTANT(GL_TEXTURE_MAG_FILTER)
	CONSTANT(GL_TEXTURE_MAG_FILTER)
	//CONSTANT(GL_TEXTURE_MAX_LEVEL)
	//CONSTANT(GL_TEXTURE_MAX_LOD)
	CONSTANT(GL_TEXTURE_MIN_FILTER)
	CONSTANT(GL_TEXTURE_MIN_FILTER)
	//CONSTANT(GL_TEXTURE_MIN_LOD)
	//CONSTANT(GL_TEXTURE_PRIORITY)
	//CONSTANT(GL_TEXTURE_RESIDENT)
	//CONSTANT(GL_TEXTURE_WRAP_R)
	CONSTANT(GL_TEXTURE_WRAP_S)
	CONSTANT(GL_TEXTURE_WRAP_S)
	CONSTANT(GL_TEXTURE_WRAP_T)
	CONSTANT(GL_TEXTURE_WRAP_T)
	CONSTANT(GL_TRIANGLES)
	CONSTANT(GL_TRIANGLE_FAN)
	CONSTANT(GL_TRIANGLE_STRIP)
	CONSTANT(GL_TRUE)
	CONSTANT(GL_UNPACK_ALIGNMENT)
	CONSTANT(GL_UNSIGNED_BYTE)
	CONSTANT(GL_UNSIGNED_SHORT)
	CONSTANT(GL_UNSIGNED_SHORT_1_5_5_5_REV)
	CONSTANT(GL_UNSIGNED_SHORT_4_4_4_4)
	CONSTANT(GL_UNSIGNED_SHORT_4_4_4_4_REV)
	CONSTANT(GL_UNSIGNED_SHORT_5_5_5_1)
	CONSTANT(GL_UNSIGNED_SHORT_5_6_5)
	CONSTANT(GL_VALIDATE_STATUS)
	CONSTANT(GL_VENDOR)
	CONSTANT(GL_VERSION)
	CONSTANT(GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING)
	CONSTANT(GL_VERTEX_ATTRIB_ARRAY_ENABLED)
	CONSTANT(GL_VERTEX_ATTRIB_ARRAY_NORMALIZED)
	CONSTANT(GL_VERTEX_ATTRIB_ARRAY_SIZE)
	CONSTANT(GL_VERTEX_ATTRIB_ARRAY_STRIDE)
	CONSTANT(GL_VERTEX_ATTRIB_ARRAY_TYPE)
	CONSTANT(GL_VERTEX_SHADER)
	CONSTANT(GL_VIEWPORT)
	CONSTANT(GL_ZERO)


	//FUN(glAlphaFunc)
	FUN(glActiveTexture)
	FUN(glAttachShader)

	FUN(glBindAttribLocation)
	FUN(glBindBuffer)
	FUN(glBindTexture)
	FUN(glBlendFunc)
	FUN(glBufferData)
	FUN(glBufferSubData)

	FUN(glCheckFramebufferStatus)
	FUN(glClear)
	FUN(glClearColor)
	FUN(glCullFace)
	//FUN(glClearAccum)
	//FUN(glClearDepth)
	//FUN(glClearIndex)
	FUN(glClearStencil)
	FUN(glClearDepthf)
	FUN(glColorMask)
	FUN(glCompileShader)
	FUN(glCullFace)
	//FUN(glCompressedTexImage2D)
	//FUN(glCompressedTexSubImage2D)
	//FUN(glCopyTexImage2D)
	//FUN(glCopyTexSubImage2D)
	FUN(glCreateProgram)
	FUN(glCreateShader)

	FUN(glDeleteBuffer)
	FUN(glDeleteFramebuffer) // glDeleteFramebuffers
	FUN(glDeleteProgram)
	FUN(glDeleteTexture)
	FUN(glDeleteRenderbuffer) // glDeleteRenderbuffers
	FUN(glDeleteShader)
	FUN(glDetachShader)
	FUN(glDeleteTexture) // glDeleteTextures
	FUN(glDepthFunc)
	FUN(glDepthMask)
	FUN(glDepthRangef)
	FUN(glDisable)
	FUN(glDisableVertexAttribArray)
	FUN(glDrawArrays)
	//FUN(glDrawBuffer)
	//FUN(glDrawElements)

	FUN(glEnable)
	FUN(glEnableVertexAttribArray)

	FUN(glFinish)
	FUN(glFlush)
	//FUN(glFramebufferRenderbuffer)
	//FUN(glFramebufferTexture2D)
	//FUN(glFrontFace)

	FUN(glGetAttribLocation)
	FUN(glGetBooleanv)
	FUN(glGenBuffer)
	FUN(glGetBufferParameteriv)
	FUN(glGetError)
	FUN(glGetFloatv)
	FUN(glGetFramebufferAttachmentParameteriv)
	FUN(glGetIntegerv)
	//FUN(glGetProgramInfoLog)
	FUN(glGetProgramiv)
	FUN(glGetRenderbufferParameteriv)
	FUN(glGetUniformLocation)
	FUN(glGetShaderiv)
	FUN(glGetShaderSource)
	FUN(glGetString)
	FUN(glGetTexParameterfv)
	FUN(glGetUniformLocation)

	FUN(glHint)

	FUN(glIsBuffer)
	FUN(glIsEnabled)
	//FUN(glIndexMask)

	FUN(glLineWidth)
	FUN(glLinkProgram)
	//FUN(glLogicOp)

	FUN(glReadPixels)

	FUN(glScissor)
	FUN(glStencilFunc)
	FUN(glStencilFuncSeparate)
	FUN(glStencilMask)
	FUN(glStencilMaskSeparate)
	FUN(glStencilOp)
	FUN(glStencilOpSeparate)

	FUN(glPixelStorei)

	FUN(glTexImage2D)
	FUN(glTexParameterf)
	FUN(glTexParameteri)
	//FUN(glTexParameteriv)
	//FUN(glTexSubImage2D)

	FUN(glUniform1f)
	//FUN(glUniform2f)
	FUN(glUniform3f)
	FUN(glUniform4f)
	FUN(glUniform1i)
	FUN(glUniform2i)
	FUN(glUniform3i)
	FUN(glUniform4i)
	//FUN(glUniform1fv)
	//FUN(glUniform1iv)
	//FUN(glUniform2fv)
	//FUN(glUniform2iv)
	//FUN(glUniform3iv)
	//FUN(glUniform4iv)
	FUN(glUniformMatrix3fv)
	FUN(glUniformMatrix4fv)
	FUN(glUseProgram)

	FUN(glValidateProgram)
	FUN(glVertexAttrib1f)
	FUN(glVertexAttrib2f)
	FUN(glVertexAttrib3f)
	FUN(glVertexAttrib4f)
	//FUN(glVertexAttrib1fv)
	//FUN(glVertexAttrib2fv)
	//FUN(glVertexAttrib3fv)
	//FUN(glVertexAttrib4fv)
	FUN(glViewport)

	FUN(glVertexAttribPointer)
}

#define MYNAME "luaopengles"
#define VERSION "0.2"

LUALIB_API int luaopen_luagles(lua_State * L)
{
   register_gl(L);

   lua_newtable(L);

   lua_pushstring(L, "VERSION");
   lua_pushstring(L, VERSION);
   lua_settable(L, -3);

   lua_pushstring(L, MYNAME);
   lua_pushvalue(L, -2);
   lua_settable(L, LUA_GLOBALSINDEX);

   return 1;
}

#include "luaopengles_ext_ios.h"
#include "memarray.h"

LUALIB_API int luaopen_luagleslibs(lua_State * L)
{
	luaopen_luagles(L);
	luaopen_memarray(L);
	luaopen_luaopengles_ext_ios(L);
	return 1;
}
