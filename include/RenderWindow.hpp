#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class RenderWindow 
{
public:
	RenderWindow(const char* title, int w, int h);
	void cleanUp();
private:
	SDL_Window* window;
	SDL_Renderer* renderer;
};