#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Entity.hpp"

Entity::Entity(double p_x, double p_y, SDL_Texture* p_tex)
:x(p_x),y(p_y),tex(p_tex)
{
	currentFrame.x = 0;
	currentFrame.y = 0;
	currentFrame.w = 10;
	currentFrame.h = 10;
}
double Entity::getX()
{
	return x;
}
double Entity::getY()
{
	return y;
}
SDL_Texture* Entity::getTex()
{
	return tex;
}
SDL_Rect Entity::getCurrentFrame()
{
	return currentFrame;
}