#version 300 es

#ifdef GL_ES
precision highp float;
#endif

in vec4 fragColor;
out vec4 outColor;

void main(){
	outColor = vec4(fragColor[0], fragColor[1], fragColor[2], fragColor[3]);
}