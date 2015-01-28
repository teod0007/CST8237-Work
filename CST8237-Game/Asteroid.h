#pragma once
#include "GameObject.h"
class Asteroid: public GameObject
{
	float xVelocity,yVelocity;
public:
	 
	 Asteroid();
	 virtual void Initialize();
  
	 virtual void Update(float dt);
	 virtual void Draw(SDL_Renderer *renderer, float dt);

	 Vector3& GetPosition();
};