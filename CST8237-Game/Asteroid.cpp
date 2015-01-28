

#include "Asteroid.h"
#include <SDL.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

struct SDL_Renderer;

Asteroid::Asteroid():GameObject(){}

void Asteroid::Initialize()
{
	_transform.rotation.x = 640.0f;
	_transform.rotation.y = 640.0f;
	_transform.scale.x = 1;
	_transform.scale.y = 1;
	xVelocity= 0.0f;
	yVelocity= 0.0f;

	srand (SDL_GetTicks()/4);
	int randomX = rand() % 500;
	srand (SDL_GetTicks()/2);
	int randomY = rand() % 500;
	srand (SDL_GetTicks()/3);
	int randomV = rand() % 30;
	if(randomV<10) randomV = -10;
	float radians = atan2f(randomX,randomY);
	yVelocity = randomV * cos(radians);
	xVelocity = randomV * sin(radians);
}

void Asteroid::Update(float dt)
{
	
   
	float xMov=0.0f,yMov = 0.0f;
	float delta = dt;
	xMov += (xVelocity * delta);
	yMov += (yVelocity * delta);
	_transform.rotation.x-=(xMov);
	_transform.rotation.y-=(yMov);

   if(_transform.rotation.x < 0)
		_transform.rotation.x += 640;
	else
	if(_transform.rotation.x > 640)
		_transform.rotation.x -= 640;
	else
	if(_transform.rotation.y < 0)
		_transform.rotation.y += 640;
	else
	if(_transform.rotation.y > 640)
		_transform.rotation.y -= 640;
}

void Asteroid::Draw(SDL_Renderer *renderer, float dt)
{
	SDL_SetRenderDrawColor(renderer, 0,0,0,0);
	for(int i = 0; i < 360; i++)
		SDL_RenderDrawPoint(renderer,_transform.rotation.x + 10 * cos(i*3.14159f/180),_transform.rotation.y + 10 * sin(i*3.14159f/180));
}

Vector3& Asteroid::GetPosition()
{
	return _transform.rotation;
}