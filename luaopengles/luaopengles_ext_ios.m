#import <UIKit/UIKit.h>
#import <GLKit/GLKit.h>
#import "ViewController.h"
#import "lua.h"
#import "lualib.h"
#import "lauxlib.h"
#import <string.h>
#import "macros.h"
#import "memarray.h"

#include <OpenGLES/ES2/gl.h>
#include <OpenGLES/ES2/glext.h>



LUA_API int LglGenVertexArraysOES(lua_State * L)
{
	GLint arg1 = (GLint) check_GLint(L, 1);
	GLuint id = 0;
    glGenVertexArraysOES(arg1, &id);
	lua_pushnumber(L, id);
	return 1;
}

FUN_vI(glBindVertexArrayOES)

LUA_API int LglDeleteVertexArraysOES(lua_State * L)
{
	GLsizei n = (GLsizei) check_GLint(L, 1);

	if (lua_type(L, 2) != LUA_TUSERDATA)
	{
		luaL_error(L, "glDeleteVertexArraysOES argument 2: lightuserdata required\n");
	}
	
	memarray_t *memarray = (void *) lua_touserdata(L, 2);
		
    glDeleteVertexArraysOES(n, memarray->data);
	return 0;
}


LUA_API int LGLKMatrix4RotateInPlace(lua_State * L)
{
	if (lua_type(L, 1) != LUA_TUSERDATA)
	{
		luaL_error(L, "LglDeleteBuffers argument 1: lightuserdata required\n");
	}
	
	memarray_t *memarray = (void *) lua_touserdata(L, 1);
	GLKMatrix4 *m = memarray->data;
	
	GLfloat radians = (GLfloat) check_GLfloat(L, 2);
	GLfloat x = (GLfloat) check_GLfloat(L, 3);
	GLfloat y = (GLfloat) check_GLfloat(L, 4);
	GLfloat z = (GLfloat) check_GLfloat(L, 5);
	
    GLKMatrix4 result = GLKMatrix4Rotate(*m, radians, x, y, z);
	memcpy((void *)m, (void *)&result, sizeof(GLKMatrix4));
	return 0;
}


LUA_API int LGLKMatrix4TranslateInPlace(lua_State * L)
{
	if (lua_type(L, 1) != LUA_TUSERDATA)
	{
		luaL_error(L, "GLKMatrix4Translate argument 1: lightuserdata required\n");
	}
	
	memarray_t *memarray = (void *) lua_touserdata(L, 1);
	GLKMatrix4 *m = memarray->data;
	
	GLfloat x = (GLfloat) check_GLfloat(L, 2);
	GLfloat y = (GLfloat) check_GLfloat(L, 3);
	GLfloat z = (GLfloat) check_GLfloat(L, 4);

    GLKMatrix4 result = GLKMatrix4Translate(*m, x, y, z);
	memcpy((void *)m, (void *)&result, sizeof(GLKMatrix4));
	return 0;
}


LUA_API int LGLKMatrix4MakeTranslationInPlace(lua_State * L)
{
	if (lua_type(L, 1) != LUA_TUSERDATA)
	{
		luaL_error(L, "GLKMatrix4Translate argument 1: lightuserdata required\n");
	}
	
	memarray_t *memarray = (void *) lua_touserdata(L, 1);
	GLKMatrix4 *m = memarray->data;
	
	GLfloat x = (GLfloat) check_GLfloat(L, 2);
	GLfloat y = (GLfloat) check_GLfloat(L, 3);
	GLfloat z = (GLfloat) check_GLfloat(L, 4);

    GLKMatrix4 result = GLKMatrix4MakeTranslation(x, y, z);
	memcpy((void *)m, (void *)&result, sizeof(GLKMatrix4));
	return 0;
}


LUA_API int LGLKMatrix4ScaleInPlace(lua_State * L)
{
	if (lua_type(L, 1) != LUA_TUSERDATA)
	{
		luaL_error(L, "GLKMatrix4Scale argument 1: lightuserdata required\n");
	}
	
	memarray_t *memarray = (void *) lua_touserdata(L, 1);
	GLKMatrix4 *m = memarray->data;
	
	GLfloat x = (GLfloat) check_GLfloat(L, 2);
	GLfloat y = (GLfloat) check_GLfloat(L, 3);
	GLfloat z = (GLfloat) check_GLfloat(L, 4);

    GLKMatrix4 result = GLKMatrix4Scale(*m, x, y, z);
	memcpy((void *)m, (void *)&result, sizeof(GLKMatrix4));
	return 0;
}


LUA_API int LGLKMatrix4MakePerspectiveInPlace(lua_State * L)
{
	if (lua_type(L, 1) != LUA_TUSERDATA)
	{
		luaL_error(L, "GLKMatrix4Scale argument 1: lightuserdata required\n");
	}
	
	memarray_t *memarray = (void *) lua_touserdata(L, 1);
	GLKMatrix4 *m = memarray->data;
	
	GLfloat fovyRadians = (GLfloat) check_GLfloat(L, 2);
	GLfloat aspect = (GLfloat) check_GLfloat(L, 3);
	GLfloat nearZ = (GLfloat) check_GLfloat(L, 4);
	GLfloat farZ = (GLfloat) check_GLfloat(L, 5);

    GLKMatrix4 result = GLKMatrix4MakePerspective(fovyRadians, aspect, nearZ, farZ);

	memcpy(m, &result, sizeof(GLKMatrix4));
	return 1;
}


LUA_API int LGLKMatrix4MakeOrthoInPlace(lua_State * L)
{
	if (lua_type(L, 1) != LUA_TUSERDATA)
	{
		luaL_error(L, "LGLKMatrix4MakeOrthoInPlace argument 1: lightuserdata required\n");
	}
	
	memarray_t *memarray = (void *) lua_touserdata(L, 1);
	GLKMatrix4 *m = memarray->data;
   
	GLfloat left = (GLfloat) check_GLfloat(L, 2);
	GLfloat right = (GLfloat) check_GLfloat(L, 3);
	GLfloat bottom = (GLfloat) check_GLfloat(L, 4);
	GLfloat top = (GLfloat) check_GLfloat(L, 5);
	GLfloat nearZ = (GLfloat) check_GLfloat(L, 6);
	GLfloat farZ = (GLfloat) check_GLfloat(L, 7);

    GLKMatrix4 result = GLKMatrix4MakeOrtho(left, right, bottom, top, nearZ, farZ);

	memcpy(m, &result, sizeof(GLKMatrix4));
	return 1;
}


LUA_API int LGLKMatrix4MultiplyInPlace(lua_State * L)
{
    if (lua_type(L, 1) != LUA_TUSERDATA)
	{
		luaL_error(L, "GLKMatrix4Scale argument 1: lightuserdata required\n");
	}
	
	memarray_t *memarray1 = (void *) lua_touserdata(L, 1);
	GLKMatrix4 *m1 = memarray1->data;
	
    if (lua_type(L, 2) != LUA_TUSERDATA)
	{
		luaL_error(L, "GLKMatrix4Scale argument 2: lightuserdata required\n");
	}
	
	memarray_t *memarray2 = (void *) lua_touserdata(L, 2);
	GLKMatrix4 *m2 = memarray2->data;
    
	GLKMatrix4 m3 = GLKMatrix4Multiply(*m1, *m2);

	memcpy(m1, &m3, sizeof(GLKMatrix4));
    return 0;
}


LUA_API int LGLKTextureLoader_loadTextureAtPath(lua_State * L)
{
    const char *path = luaL_checklstring(L, 1, NULL);
    lua_pop(L, 1);
    if (path)
    {
        NSError *error = nil;
        GLKTextureInfo *info = [GLKTextureLoader textureWithContentsOfFile:[NSString stringWithCString:path encoding:NSUTF8StringEncoding] options:nil error:&error];
        if (info)
        {
            lua_pushinteger(L, info.name);
            return 1;
        }
        else
        {
            luaL_error(L, [[error description] cStringUsingEncoding:NSUTF8StringEncoding]);
            return 0;
        }
    }
    else
    {
        luaL_error(L, "GLKTextureLoader_loadTextureAtPath arg 1 is not a string\n");
        return 0;
    }
}

/*
#include "png.h"

void *read_rgba_png_file(const char *file_name, size_t *imageWidth, size_t *imageHeight)
{
	int width, height;
	png_byte color_type;
	png_byte bit_depth;

	png_structp png_ptr;
	png_infop info_ptr;
	int number_of_passes;
	
	printf("file_name : '%s'\n", file_name);

	char header[8];    // 8 is the maximum size that can be checked

	// open file and test for it being a png 
	//FILE *fp = fopen(file_name, "rb");
	FILE *fp = fopen(file_name, "r");
	
	fseek(fp, 0, SEEK_END);
	size_t fileSize = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	void *fileData = calloc(1, fileSize);
	fread(fileData, fileSize, 1, fp);
	printf("read all file data, %zi bytes\n", fileSize);
	
	fseek(fp, 0, SEEK_SET);
	
	
	
	if (!fp)
	{
		printf("[read_png_file] File %s could not be opened for reading", file_name);
		exit(-1);
	}

	fread(header, 1, 8, fp);
	if (png_sig_cmp((const unsigned char *)header, 0, 8))
	{
		printf("[read_png_file] File %s is not recognized as a PNG file", file_name);
		exit(-1);
	}

	// initialize stuff 
	png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
	if (!png_ptr)
	{
		printf("[read_png_file] png_create_read_struct failed");
		exit(-1);
	}

	info_ptr = png_create_info_struct(png_ptr);
	if (!info_ptr)
	{
		printf("[read_png_file] png_create_info_struct failed");
		exit(-1);
	}

	if (setjmp(png_jmpbuf(png_ptr)))
	{
		printf("[read_png_file] Error during init_io");
		exit(-1);
	}

	png_init_io(png_ptr, fp);
	png_set_sig_bytes(png_ptr, 8);

	png_read_info(png_ptr, info_ptr);

	width = png_get_image_width(png_ptr, info_ptr);
	height = png_get_image_height(png_ptr, info_ptr);
	color_type = png_get_color_type(png_ptr, info_ptr);
	
	if(color_type != PNG_COLOR_TYPE_RGB_ALPHA)
	{
		printf("png %s is not RGBA\n", file_name);
		exit(-1);
	}
	
	bit_depth = png_get_bit_depth(png_ptr, info_ptr);

	number_of_passes = png_set_interlace_handling(png_ptr);
	png_read_update_info(png_ptr, info_ptr);


	// read file 
	if (setjmp(png_jmpbuf(png_ptr)))
	{
		printf("[read_png_file] Error during read_image");
		exit(-1);
	}

	int y;
	png_bytep *row_pointers = (png_bytep*)calloc(1, sizeof(png_bytep) * height);
	int row_size = png_get_rowbytes(png_ptr,info_ptr);
	
	for (y = 0; y<height; y++)
	{
		row_pointers[y] = (png_byte *)calloc(1, row_size);
	}

	png_read_image(png_ptr, row_pointers);

	fclose(fp);

	// copy to data
	
	void *data = calloc(1, width * height * 4);
	assert(row_size == width * 4);
	
	//printf("row_size = %i\n", row_size);
	//printf("width * 4 = %i\n", width * 4);
	
	for (y = 0; y < height; y ++)
	{
		//printf("row_pointers[%i] = %p\n", y, row_pointers[y]);
		memcpy(data +  (y * row_size), row_pointers[y], row_size);
		free(row_pointers[y]);
	}
	
	free(row_pointers);
	
	*imageWidth  = width;
	*imageHeight = height;
	
	return data;
}
*/

LUA_API int LLoadTextureFile(lua_State * L)
{
	const char *file_name = check_string(L, 1);
	NSString *resource = [[NSString alloc] initWithBytes:file_name length:strlen(file_name) encoding:NSUTF8StringEncoding]; // +1?
    NSString *fullPath = [[NSBundle mainBundle] pathForResource:resource ofType:nil];
    
    
    //CGImageRef spriteImage = [UIImage imageWithContentsOfFile:fullPath].CGImage;
    CGImageRef spriteImage = [UIImage imageNamed:resource].CGImage;
    //CGImageRef spriteImage = [UIImage imageWithData:[NSData dataWithContentsOfFile:fullPath]].CGImage;
	
    if (!spriteImage)
	{
        NSLog(@"Failed to load image %@", fullPath);
        return 0;
    }
    
    size_t width  = CGImageGetWidth(spriteImage);
    size_t height = CGImageGetHeight(spriteImage);

	//assert(CGImageGetAlphaInfo(spriteImage) == kCGImageAlphaPremultipliedLast);
	
	GLubyte * spriteData = (GLubyte *) calloc(width*height*4, sizeof(GLubyte));
	
    CGContextRef spriteContext = CGBitmapContextCreate(spriteData, width, height, 8, width*4,
                                                       CGImageGetColorSpace(spriteImage), kCGImageAlphaPremultipliedLast);
    
    CGContextDrawImage(spriteContext, CGRectMake(0, 0, width, height), spriteImage);
    CGContextRelease(spriteContext);
    
    

/*
	size_t width;
	size_t height;
	
	void *data = read_rgba_png_file([fullPath UTF8String], &width, &height);
	
	printf(" width: %i\n", (int)width);
	printf("height: %i\n", (int)height);
*/
/*
    int width = 512;
    int height = 512;
    void *data = calloc(1, 512 * 512 * 4);
*/
    
	GLuint texName;
    glGenTextures(1, &texName);
    glBindTexture(GL_TEXTURE_2D, texName);
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, spriteData);
    
    free(spriteData);

	lua_pushnumber(L, texName);
	lua_pushnumber(L, width);
	lua_pushnumber(L, height);
	
	return 3;
}

LUA_API int LCompileShaderWithType(lua_State * L)
{
	const char *a1 = check_string(L, 1);
    GLuint shaderType = check_GLuint(L, 2);
    
	NSString *resource = [[NSString alloc] initWithBytes:a1 length:strlen(a1) encoding:NSUTF8StringEncoding];
	
    NSString *fileName = [[NSBundle mainBundle] pathForResource:resource ofType:nil];
	
    NSError* error;
    NSString* shaderString = [NSString stringWithContentsOfFile:fileName
                                                       encoding:NSUTF8StringEncoding error:&error];
    if (!shaderString) {
        NSLog(@"Error loading shader: %@", error.localizedDescription);
        return 0;
    }
	
    GLuint shaderHandle = glCreateShader(shaderType);
    
    const char * shaderStringUTF8 = [shaderString UTF8String];
    int shaderStringLength = [shaderString length];
    glShaderSource(shaderHandle, 1, &shaderStringUTF8, &shaderStringLength);
    
    glCompileShader(shaderHandle);
    
    GLint compileSuccess;
    glGetShaderiv(shaderHandle, GL_COMPILE_STATUS, &compileSuccess);
    if (compileSuccess == GL_FALSE) {
        GLchar messages[256];
        glGetShaderInfoLog(shaderHandle, sizeof(messages), 0, &messages[0]);
        NSString *messageString = [NSString stringWithUTF8String:messages];
        NSLog(@"%@", messageString);
        return 0;
    }
    
	lua_pushnumber(L, shaderHandle);
	
	return 1;
}


void register_glExtensions(lua_State *L)
{
	CONSTANT(GLKVertexAttribPosition)
	CONSTANT(GLKVertexAttribPosition)
	CONSTANT(GLKVertexAttribTexCoord0)
	
	FUN(GLKMatrix4ScaleInPlace)
	FUN(GLKMatrix4TranslateInPlace)
	FUN(GLKMatrix4MakeTranslationInPlace)
	FUN(GLKMatrix4RotateInPlace)
	FUN(GLKMatrix4MakePerspectiveInPlace)
	FUN(GLKMatrix4MultiplyInPlace)
	FUN(GLKMatrix4MakeOrthoInPlace)
		
	FUN(LoadTextureFile)
	FUN(CompileShaderWithType)

	FUN(glGenVertexArraysOES)
	FUN(glBindVertexArrayOES)
	FUN(glDeleteVertexArraysOES)
	FUN(glGenVertexArraysOES)
}


#define MYNAME "luaopengles_ext_ios"
#define VERSION "0.1"

LUALIB_API int luaopen_luaopengles_ext_ios(lua_State * L)
{
   register_glExtensions(L);

   lua_newtable(L);

   lua_pushstring(L, "VERSION");
   lua_pushstring(L, VERSION);
   lua_settable(L, -3);

   lua_pushstring(L, MYNAME);
   lua_pushvalue(L, -2);
   lua_settable(L, LUA_GLOBALSINDEX);

   return 1;
}
