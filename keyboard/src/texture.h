//texture.h

#ifndef __TEXTURE_H__
#define __TEXTURE_H__

#include <GLES3/gl3.h>
#include <SDL2/SDL.h>

//loads 2D texture from file

GLuint textureLoad(const char* filename);

GLuint textureLoadFromFont(const char* filename, const char* string, int size, SDL_Color color);

GLuint textureFromSDLSurface(SDL_Surface* surface);

void replaceTextureFromSDLSurface(GLuint texture, SDL_Surface* textureSurface);

void textureDestroy(GLuint textureName);

#endif