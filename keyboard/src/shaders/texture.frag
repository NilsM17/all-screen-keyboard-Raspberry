#version 300 es

#ifdef GL_ES
precision highp float;
#endif

in vec2 texCoord;
in float alpha;
out vec4 fragColor;

uniform sampler2D textureSampler;

void main(){
	fragColor = texture(textureSampler, texCoord);
	fragColor[3] *= alpha;
}