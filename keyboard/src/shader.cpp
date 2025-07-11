//shader.cpp

#include "shader.h"

#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengles2.h>

#ifdef _MSC_VER
#pragma warning(disable:4996)
#endif

static size_t getFileLength(FILE* file){
	size_t length;
	size_t currPos = ftell(file);
	fseek(file, 0, SEEK_END);
	length = ftell(file);
	fseek(file, currPos, SEEK_SET);
	return length;
}

static GLuint shaderLoad(const char* filename, GLenum shaderType){
	FILE* file = fopen(filename, "r");
	if (!file){
		SDL_Log("Cannot open file: %s\n", filename);
		return 0;
	}
	
	size_t length = getFileLength(file);

	//allocate space for the file plus 0x00 termination byte
	GLchar* shaderSrc = (GLchar*)calloc(length + 1, 1);
	if (!shaderSrc){
		SDL_Log("Insufficent memory to open: %s\n", filename);
		fclose(file);
		file = NULL;
		return 0;
	}
	
	//read shader file to buffer
	fread(shaderSrc, 1, length, file);
	//close
	fclose(file);
	file = NULL;

	//create shader program
	GLuint shader = glCreateShader(shaderType);
	glShaderSource(shader, 1, (const GLchar**)&shaderSrc, NULL);
	free(shaderSrc);
	shaderSrc = NULL;

	//compile shader
	glCompileShader(shader);
	GLint compileSucceeded = GL_FALSE;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &compileSucceeded);
	if (!compileSucceeded){
		//compilation failed
		SDL_Log("Compilation of shader file failed: %s\n", filename);
		GLint logLength = 0;
		glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &logLength);
		GLchar* errlog = (GLchar*)malloc(logLength);
		if (errlog){
			glGetShaderInfoLog(shader, logLength, &logLength, errlog);
			SDL_Log("%s\n", errlog);
			free(errlog);
		}
		else {
			SDL_Log("Could not get shader log, out of memory\n");			
		}
		glDeleteShader(shader);
		shader = 0;
	}
	return shader;
}

static void shaderDestroy(GLuint shaderID){
	glDeleteShader(shaderID);
}

GLuint shader_h::shaderProgamLoad(const char* vertexShaderFilename, const char* fragmentShaderFilename){
	GLuint vertexShader = shaderLoad(vertexShaderFilename, GL_VERTEX_SHADER);
	if (!vertexShader){
		SDL_Log("Could not load vertex shader: %s\n", vertexShaderFilename);
		return 0;
	}

	GLuint fragmentShader = shaderLoad(fragmentShaderFilename, GL_FRAGMENT_SHADER);
	if (!fragmentShader){
		SDL_Log("Could not load fragment shader: %s\n", fragmentShaderFilename);
		return 0;
	}

	GLuint shaderProgram = glCreateProgram();
	if (shaderProgram){
		glAttachShader(shaderProgram, vertexShader);
		glAttachShader(shaderProgram, fragmentShader);

		glLinkProgram(shaderProgram);

		GLint linkingOK = GL_FALSE;
		glGetProgramiv(shaderProgram, GL_LINK_STATUS, &linkingOK);
		if(!linkingOK){
			SDL_Log("Linking shader program failed");
			GLint logLength = 0;
			glGetProgramiv(shaderProgram, GL_INFO_LOG_LENGTH, &logLength);
			GLchar* errLog = (GLchar*)malloc(logLength);
			if (errLog){
				glGetProgramInfoLog(shaderProgram, logLength, &logLength, errLog);
				SDL_Log("%s\n", errLog);
				free(errLog);
			}
			else{
				SDL_Log("Out of memory to fetch shader program link error");
			}
			glDeleteProgram(shaderProgram);
			shaderProgram = 0;
		}
	}
	else{
		SDL_Log("Could not create shader program");
	}
	//free individual shader programs
	shaderDestroy(vertexShader);
	shaderDestroy(fragmentShader);
	
	//return shader program
	return shaderProgram;	
}

//destroy shader program
void shader_h::shaderProgramDestroy(GLuint shaderProgram){
	glDeleteProgram(shaderProgram);
}