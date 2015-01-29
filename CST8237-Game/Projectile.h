#pragma once
#include "GameObject.h"

/**
* \class Projectile.h
* \brief A class that represents the object player 
* in the game.
* \author Emanuel Teodoro Sousa
* \date January 20, 2015
*/

class Projectile: public GameObject
{

	float _xVelocity,_yVelocity,_maxTime;
public:
	 Projectile();
	 Projectile(Transform &playerPosition);
/**
* \fn void Projectile::Initialize()
* \brief A function that we値l use as to define how our 
* object is initialized.
*/
	 virtual void Initialize();
/**
* \fn void Projectile::Update(float dt)
* \brief A virtual function that we値l use as to define how our 
* object is updated.
* \param dt The time in fractions of a second since the last pass.
*/ 
	 virtual void Update(float dt);
/**
* \fn void Projectile::Draw(SDL_Renderer *renderer, float dt)
* \brief A virtual function that we値l use as to define how our 
* object is drawn to the screen.
* \param renderer The SDL renderer used to draw the object.
* \param dt The time in fractions of a second since the last pass.
*/
	 virtual void Draw(SDL_Renderer *renderer, float dt);
/**
* \fn void Projectile::GetMaxTime()
* \brief A function that we値l use to get
* the maxTime of the projectile.
*/
	 float GetMaxTime();
/**
* \fn Vector2& Projectile::GetPosition()
* \brief A function that we値l use to get
* the Vector2 component inside _transform.
*/
	 Vector2& GetPosition();
};