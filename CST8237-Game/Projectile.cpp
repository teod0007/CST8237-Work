
#include "Projectile.h"
#include <SDL.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

struct SDL_Renderer;

Projectile::Projectile():GameObject(){

}

Projectile::Projectile(Transform &playerPosition):GameObject(){
	
	_texture = nullptr;
	_transform.rotation.x = playerPosition.rotation.x-playerPosition.position.x;
	_transform.rotation.y = playerPosition.rotation.y-playerPosition.position.y;
	_transform.rotation.z = playerPosition.rotation.z;
	_transform.position.x = playerPosition.position.x;
	_transform.position.y = playerPosition.position.y;
}

void Projectile::Initialize()
{
	_maxBounces = 3;
	float radians = atan2f(_transform.rotation.x,_transform.rotation.y);
	_yVelocity = 300.0f * cos(radians);
	_xVelocity = 300.0f * sin(radians); 
}

void Projectile::Update(float dt)
{
	
   
	float xMov=0.0f,yMov = 0.0f;
   float delta = dt;
   xMov += (_xVelocity * delta);
   yMov += (_yVelocity * delta);
   _transform.position.x-=(xMov);
   _transform.position.y-=(yMov);
   //_maxTime += delta;

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
	if(_texture == nullptr)
		_texture = IMG_LoadTexture( renderer, "./cannonball.png");
	SDL_Rect textureRect = {_transform.position.x-2,_transform.position.y-2,4,4};
	SDL_SetRenderDrawColor(renderer, 0,0,0,0);
	SDL_RenderCopyEx(renderer,_texture,NULL,&textureRect,_transform.rotation.z,NULL,SDL_FLIP_NONE);
	/*SDL_RenderDrawPoint(renderer,_transform.position.x,_transform.position.y);
	SDL_RenderDrawRect(renderer,&textureRect);*/
}

Vector2& Projectile::GetPosition()
{
	return _transform.position;
}

void Projectile::ReverseY()
{
	_yVelocity *= -1;
}

void Projectile::ReverseX()
{
	_xVelocity *= -1;
}

int& Projectile::GetBounces()
{
	return _maxBounces;
}