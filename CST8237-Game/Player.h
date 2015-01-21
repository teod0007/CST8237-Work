#pragma once
#include "GameObject.h"
class Player: public GameObject
{
public:
	 
	 Player();
	 virtual void Initialize();
  
	 virtual void Update(float dt);
	 virtual void Draw(SDL_Renderer *renderer, float dt);
	
};