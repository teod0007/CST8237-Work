#pragma once
#include "GameObject.h"
class Player: public GameObject
{
	Vector2 _pos1,_pos2;
	float _xVelocity,_yVelocity,_acceleration;
	Acceleration _accDirection;
public:
	 
	 Player();
	 virtual void Initialize();
  
	 virtual void Update(float dt);
	 virtual void Draw(SDL_Renderer *renderer, float dt);
	 void Move(Acceleration);
	 void Turn(Direction);
	 Transform& GetTransform(); 
	 Vector3& GetPosition();
};