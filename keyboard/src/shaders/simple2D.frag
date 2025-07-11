#version 300 es

#ifdef GL_ES
precision highp float;
#endif

in vec4 color;	//input from vertex shader

out vec4 fragColor;	//output color of fragment

void main(){
	fragColor = color;
}