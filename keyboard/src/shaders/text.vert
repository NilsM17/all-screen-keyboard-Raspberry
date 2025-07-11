#version 300 es

layout(location = 0) in vec2 vertPos;
layout(location = 1) in vec2 vertTexCoord;
uniform vec3 XYSize;
uniform int index;

out vec2 texCoord;

void main(){
	texCoord = vec2(vertTexCoord[0], vertTexCoord[1]);
	gl_Position = vec4(((vertPos[0] + (float(index) * abs(vertPos[0] * 2.0))) * XYSize[2]) + XYSize[0], 
						(vertPos[1] * XYSize[2]) + XYSize[1],
						0.0, 1.0);
}