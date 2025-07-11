//text.cpp

#include "text.h"

text::text(const char* inputString, int x, int y, float newSize, int r, int g, int b, int a){
	outputString = inputString;
	
	
	//turn coordinates and color into openGL format
	float windowWidthHalf = 2560.0f * 0.5f;
	float windowHeightHalf = 1440.0f * 0.5f;

	locationX = (static_cast<float>(x) - windowWidthHalf) / windowWidthHalf;
	locationY = -((static_cast<float>(y) - windowHeightHalf) / windowHeightHalf);
	size = newSize;
	
	c.r = static_cast<float>(r) / 255.0f;
	c.g = static_cast<float>(g) / 255.0f;
	c.b = static_cast<float>(b) / 255.0f;
	c.a = static_cast<float>(a) / 255.0f;
	return;
}

const char* text::getText(){
	return outputString.c_str();
}

void text::updateText(const char* updateString){
	outputString = updateString;
	return;
}

void text::updateLocation(int x, int y){
	locationX = x;
	locationY = y;
	return;
}

void text::updateSize(int newSize){
	size = newSize;
	return;
}

void text::updateColor(int r, int g, int b, int a){
	c.r = static_cast<float>(r) / 255.0f;
	c.g = static_cast<float>(g) / 255.0f;
	c.b = static_cast<float>(b) / 255.0f;
	c.a = static_cast<float>(a) / 255.0f;
	return;
}