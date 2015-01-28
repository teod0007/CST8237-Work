

#include "Player.h"
#include <SDL.h>

struct SDL_Renderer;

Player::Player():GameObject(){}

void Player::Initialize()
{
	_transform.position.x = 100.0f;
	_transform.position.y = 100.0f;
	_transform.rotation.x = 100.0f;
	_transform.rotation.y = 105.0f;
	_transform.rotation.z = 90;
	_pos1.x = 90;
	_pos1.y = 110;
	_pos2.x = 110;
	_pos2.y = 110;
	_transform.scale.x = 1;
	_transform.scale.y = 1;
	_xVelocity= 0.0f;
	_yVelocity= 0.0f;
	_acceleration = 5.0f;
	_accDirection = NONE;
}

void Player::Update(float dt)
{
   float xMov=0.0f,yMov = 0.0f;
   float delta = dt;
   float radians;
   Vector2 actual = {_transform.position.x-_transform.rotation.x,_transform.position.y-_transform.rotation.y};
   radians = MathUtils::AtanF(actual.x,actual.y);

   
   if(_accDirection == FORWARD)
   {
	   _yVelocity -= MathUtils::VectorDecomposition(_acceleration,radians,Y);
	   _xVelocity -= MathUtils::VectorDecomposition(_acceleration,radians,X);
   }
   if(_accDirection == BACKWARD)
   {
	   _yVelocity += MathUtils::VectorDecomposition(_acceleration,radians,Y);
	   _xVelocity += MathUtils::VectorDecomposition(_acceleration,radians,X);
   }
   _accDirection = NONE;

   xMov += (_xVelocity * delta);
   yMov += (_yVelocity * delta);
   _transform.position.x -= (xMov);
   _transform.position.y -= (yMov);
   _pos1.x-=(xMov);
   _pos1.y-=(yMov);
   _pos2.x-=(xMov);
   _pos2.y-=(yMov);
   _transform.rotation.x -= (xMov);
   _transform.rotation.y -= (yMov);

   if(_transform.rotation.x < 0){
		
		_transform.rotation.x += 640;
		_transform.position.x += 640;
		_pos1.x += 640;
		_pos2.x += 640;
	}else
	if(_transform.rotation.x > 640){
		
		_transform.rotation.x -= 640;
		_transform.position.x -= 640;
		_pos1.x -= 640;
		_pos2.x -= 640;
	}else
	if(_transform.rotation.y < 0){
		
		_transform.rotation.y += 640;
		_transform.position.y += 640;
		_pos1.y += 640;
		_pos2.y += 640;
	}else
	if(_transform.rotation.y > 640){
		
		_transform.rotation.y -= 640;
		_transform.position.y -= 640;
		_pos1.y -= 640;
		_pos2.y -= 640;
	}
}

void Player::Draw(SDL_Renderer *renderer, float dt)
{
	SDL_SetRenderDrawColor(renderer, 0,0,0,0);
		
	SDL_RenderDrawLine(renderer,_transform.position.x,_transform.position.y,_pos1.x,_pos1.y);
	SDL_RenderDrawLine(renderer,_transform.position.x,_transform.position.y,_pos2.x,_pos2.y);
	SDL_RenderDrawLine(renderer,_pos1.x,_pos1.y,_pos2.x,_pos2.y);
}

void Player::Move(Acceleration a){
	_accDirection = a;
}

void Player::Turn(Direction d){
	    _transform.position = MathUtils::Rotate(_transform.position,_transform.rotation, d);
		_pos1 = MathUtils::Rotate(_pos1,_transform.rotation, d);
		_pos2 = MathUtils::Rotate(_pos2,_transform.rotation, d);
}

Transform& Player::GetTransform()
{
	return _transform;
}

Vector3& Player::GetPosition()
{
	return _transform.rotation;
}