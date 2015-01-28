#pragma once
#include "GameObject.h"
class Projectile: public GameObject
{

	float _xVelocity,_yVelocity,_maxTime;
public:
	 Projectile();
	 Projectile(Transform &playerPosition);
	 virtual void Initialize();
  
	 virtual void Update(float dt);
	 virtual void Draw(SDL_Renderer *renderer, float dt);

	 float GetMaxTime();
	 Vector2& GetPosition();
};