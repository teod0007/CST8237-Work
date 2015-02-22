

#include "Player.h"
#include <SDL.h>

struct SDL_Renderer;

Player::Player():GameObject(){}

void Player::Initialize()
{
	//_transform.position.x = 100.0f;
	//_transform.position.y = 100.0f;
	_transform.rotation.x = _transform.position.x;
	_transform.rotation.y = _transform.position.y + 5;
	_transform.rotation.z = 0;
	_pos1.x = _transform.position.x - 10;
	_pos1.y = _transform.position.y + 10;
	_pos2.x = _transform.position.x + 10;;
	_pos2.y = _transform.position.y + 10;
	_transform.scale.x = 1;
	_transform.scale.y = 1;
	_xVelocity= 0.0f;
	_yVelocity= 0.0f;
	_acceleration = 100.0f;
	_accDirection = NONE;
	_deadTime = 0;
	_inactiveTime = 0;
	_isDead = false;
	_isActive = true;
	_texture = nullptr;
}

void Player::Update(float dt)
{
   float xMov=0.0f,yMov = 0.0f;
   float delta = dt;
   float radians;
   Vector2 actual = {_transform.position.x-_transform.rotation.x,_transform.position.y-_transform.rotation.y};
   radians = MathUtils::AtanF(actual.x,actual.y);

   if(!_isDead)
   {
	   
		   if(_accDirection == FORWARD)
		   {
			   _yVelocity = -MathUtils::VectorDecomposition(_acceleration,radians,Y);
			   _xVelocity = -MathUtils::VectorDecomposition(_acceleration,radians,X);
		   }
		   else
		   if(_accDirection == BACKWARD)
		   {
			   _yVelocity = MathUtils::VectorDecomposition(_acceleration,radians,Y);
			   _xVelocity = MathUtils::VectorDecomposition(_acceleration,radians,X);
		   }
		   else
		   if(_accDirection == NONE)
		   {
			   _yVelocity = 0;
			   _xVelocity = 0;
		   }
		   _accDirection = NONE;

		   xMov += (_xVelocity * delta);
		   yMov += (_yVelocity * delta);
		   /*
		   _transform.position.x -= (xMov);
		   _transform.position.y -= (yMov);
		   _pos1.x-=(xMov);
		   _pos1.y-=(yMov);
		   _pos2.x-=(xMov);
		   _pos2.y-=(yMov);
		   _transform.rotation.x -= (xMov);
		   _transform.rotation.y -= (yMov);
		   */
		   AddPositionX(-xMov);
		   AddPositionY(-yMov);

		   if(_transform.rotation.x < 0){
		
				/*_transform.rotation.x += 640;
				_transform.position.x += 640;
				_pos1.x += 640;
				_pos2.x += 640;
				*/
			   AddPositionX(640);
			}else
			if(_transform.rotation.x > 640){
		
				/*_transform.rotation.x -= 640;
				_transform.position.x -= 640;
				_pos1.x -= 640;
				_pos2.x -= 640;*/
				AddPositionX(-640);
			}else
			if(_transform.rotation.y < 0){
		
				/*_transform.rotation.y += 640;
				_transform.position.y += 640;
				_pos1.y += 640;
				_pos2.y += 640;*/
				AddPositionY(640);
			}else
			if(_transform.rotation.y > 640){
				/*
				_transform.rotation.y -= 640;
				_transform.position.y -= 640;
				_pos1.y -= 640;
				_pos2.y -= 640;*/
				AddPositionY(-640);
			}
		
	}
   else
   {
	   _deadTime += delta;
	   Turn(RIGHT, 0.1);
	   if(_deadTime >= 3)
		{
			   _isDead = false;
			   _deadTime = 0;
		}
   }
   if(!_isActive)
   {
		_inactiveTime += delta;
		   if(_inactiveTime >= 3)
		   {
			   _isActive = true;
			   _inactiveTime = 0;
		   }
   }
}

void Player::Draw(SDL_Renderer *renderer, float dt)
{
	SDL_SetRenderDrawColor(renderer, 0,0,0,0);
		
	if(_texture == nullptr)
		_texture = IMG_LoadTexture( renderer, "./tank.png");
	SDL_Rect textureRect = {_transform.rotation.x-10,_transform.rotation.y-10,20,20};
	SDL_RenderCopyEx(renderer,_texture,NULL,&textureRect,_transform.rotation.z,NULL,SDL_FLIP_NONE);

	/*SDL_RenderDrawLine(renderer,_transform.position.x,_transform.position.y,_pos1.x,_pos1.y);
	SDL_RenderDrawLine(renderer,_transform.position.x,_transform.position.y,_pos2.x,_pos2.y);
	SDL_RenderDrawLine(renderer,_pos1.x,_pos1.y,_pos2.x,_pos2.y);*/

	//SDL_RenderDrawRect(renderer,&textureRect);
}

void Player::Move(Acceleration a){
	_accDirection = a;
}

void Player::Turn(Direction d, float dt){
	    _transform.position = MathUtils::Rotate(_transform.position,_transform.rotation, d, dt);
		_pos1 = MathUtils::Rotate(_pos1,_transform.rotation, d, dt);
		_pos2 = MathUtils::Rotate(_pos2,_transform.rotation, d, dt);
}

Transform& Player::GetTransform()
{
	return _transform;
}

Vector3& Player::GetPosition()
{
	return _transform.rotation;
}

void Player::AddPositionX(float x)
{
	_transform.rotation.x += x;
	_transform.position.x += x;
	_pos1.x += x;
	_pos2.x += x;
}

void Player::AddPositionY(float y)
{
	_transform.rotation.y += y;
	_transform.position.y += y;
	_pos1.y += y;
	_pos2.y += y;
}

void Player::SetPosition(float x, float y)
{
	_transform.position.x = x;
	_transform.position.y = y;
	
}

void Player::SuspendActions()
{
	_isActive = false;
}

void Player::DeathRotation()
{
	_isDead = true;
}

bool Player::IsActive()
{
	return _isActive;
}

bool Player::IsDead()
{
	return _isDead;
}