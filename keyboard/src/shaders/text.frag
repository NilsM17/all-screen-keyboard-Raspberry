#version 300 es

#ifdef GL_ES
precision highp float;
#endif

in vec2 texCoord;

uniform vec4 color;
uniform int charIndex;

out vec4 fragColor;

uniform sampler2D textureSampler;

vec2 getCharUV(int charIndex, vec2 texCoord){
	int col = 16;
	int row = 8;
	
	//calculate column and row based on ASCII charIndex
	int charX = charIndex % col;	//column 0-15
	int charY = charIndex / col;	//row 0-7
	
	//calculate UV
	vec2 charSize = vec2(1.0 / float(col), 1.0 / float(row));
	vec2 charStartUV = vec2(float(charX) * charSize.x, float(charY) * charSize.y);
	
	//final UV coordinates to sample texture
	return charStartUV + texCoord * charSize;
}

void main(){
	fragColor = texture(textureSampler, getCharUV(charIndex, texCoord));
	fragColor[3] *= color[3];
	fragColor.rgb = color.rgb;
}