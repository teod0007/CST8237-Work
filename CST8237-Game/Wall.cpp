

#include "Wall.h"
#include <SDL.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

struct SDL_Renderer;

Wall::Wall(float x, float y, float h, float w):GameObject(){
	origin.x = x;
	origin.y = y;
	origin.h = h;
	origin.w = w;
}

void Wall::Initialize()
{
	
}

void Wall::Update(float dt)
{
	
}

void Wall::Draw(SDL_Renderer *renderer, float dt)
{
	SDL_SetRenderDrawColor(renderer, 0,0,0,0);
	SDL_RenderDrawLine(renderer,origin.x,origin.y,origin.x+origin.w,origin.y);
	SDL_RenderDrawLine(renderer,origin.x,origin.y,origin.x,origin.y+origin.h);
	SDL_RenderDrawLine(renderer,origin.x+origin.w,origin.y+origin.h,origin.x+origin.w,origin.y);
	SDL_RenderDrawLine(renderer,origin.x+origin.w,origin.y+origin.h,origin.x,origin.y+origin.h);
	
}

Vector4& Wall::GetPosition()
{
	return origin;
}