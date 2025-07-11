#version 300 es
#ifdef GL_ES
precision highp float;	////high precision used to calculate float (check if affects mali GPU)
#endif	

in vec2 vertPos;
in vec4 inColor;

out vec4 fragColor;

void main(){
	fragColor = inColor;		//pass to vertexShader
	gl_Position = vec4(vertPos, 0.0, 1.0);
}