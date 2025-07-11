#version 300 es		//GLSL for OpenGL ES 3.0.0

in vec2 vertPos;	//input

out vec4 color;		//output

const vec4 white = vec4(1.0, 1.0, 0.0, 1.0);

void main(){
	color = vec4(0.0, vertPos[0], vertPos[1], 1.0);//white;
	//gl_Position is predefined output in GLSL
	gl_Position = vec4(vertPos, 0.0, 1.0);
}