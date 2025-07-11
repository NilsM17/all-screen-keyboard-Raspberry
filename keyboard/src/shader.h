//shader.h

#ifndef __SHADER_H__
#define __SHADER_H__

#include <GLES3/gl3.h>

/*	Loads a vertex and fragement shader from disk and compiles them into a shader program
*/

class shader_h{
public:
//create shader program
	GLuint shaderProgamLoad(const char* vertexShaderFilename, const char* fragmentShaderFilename);
//destroy shader program
	void shaderProgramDestroy(GLuint shaderProgram);

};

#endif