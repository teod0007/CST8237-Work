#pragma once
#include "GameObject.h"

/**
* \class Asteroid.h
* \brief A class that represents the objects of single asteroids in 
* the game.
* \author Emanuel Teodoro Sousa
* \date January 20, 2015
*/

class Wall: public GameObject
{
	Vector4 origin;
public:
	 
	 Wall(float x, float y, float h, float w);
/**
* \fn void Asteroid::Initialize()
* \brief A function that we値l use as to define how our 
* object is initialized.
*/
	 virtual void Initialize();
/**
* \fn void Asteroid::Update(float dt)
* \brief A virtual function that we値l use as to define how our 
* object is updated.
* \param dt The time in fractions of a second since the last pass.
*/  
	 virtual void Update(float dt);
/**
* \fn void Asteroid::Draw(SDL_Renderer *renderer, float dt)
* \brief A virtual function that we値l use as to define how our 
* object is drawn to the screen.
* \param renderer The SDL renderer used to draw the object.
* \param dt The time in fractions of a second since the last pass.
*/
	 virtual void Draw(SDL_Renderer *renderer, float dt);
/**
* \fn Vector4& Wall::GetPosition()
* \brief A function that we値l use as to return the position
* of this object on the screen.
*/
	 Vector4& GetPosition();
};