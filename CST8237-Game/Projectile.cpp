
#include "Projectile.h"
#include <SDL.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

struct SDL_Renderer;

Projectile::Projectile():GameObject(){

}

Projectile::Projectile(Transform &playerPosition):GameObject(){

	_transform.rotation.x = playerPosition.rotation.x-playerPosition.position.x;
	_transform.rotation.y = playerPosition.rotation.y-playerPosition.position.y;
	_transform.position.x = playerPosition.position.x;
	_transform.position.y = playerPosition.position.y;
}

void Projectile::Initialize()
{
	_maxTime = 0.0f;
	float radians = atan2f(_transform.rotation.x,_transform.rotation.y);
	_yVelocity = 100.0f * cos(radians);
	_xVelocity = 100.0f * sin(radians); 
}

void Projectile::Update(float dt)
{
	
   
	float xMov=0.0f,yMov = 0.0f;
   float delta = dt;
   xMov += (_xVelocity * delta);
   yMov += (_yVelocity * delta);
   _transform.position.x-=(xMov);
   _transform.position.y-=(yMov);
   _maxTime += delta;

   if(_transform.position.x < 0)
		_transform.position.x += 640;
	else
	if(_transform.position.x > 640)
		_transform.position.x -= 640;
	else
	if(_transform.position.y < 0)
		_transform.position.y += 640;
	else
	if(_transform.position.y > 640)
		_transform.position.y -= 640;
}

void Projectile::Draw(SDL_Renderer *renderer, float dt)
{
	SDL_SetRenderDrawColor(renderer, 0,0,0,0);
	SDL_RenderDrawPoint(renderer,_transform.position.x,_transform.position.y);
}

float Projectile::GetMaxTime()
{
	return _maxTime;
}

Vector2& Projectile::GetPosition()
{
	return _transform.position;
}
