#pragma once 

#include "MathUtils.h"
#include <SDL_image.h>

struct SDL_Renderer;

/**
* \class GameObject.h
* \brief An abstract class that represents a single object that can  
* be placed and manipulated in the world.
* \author Emanuel Teodoro Sousa
* \date January 20, 2015
*/

class GameObject
{
public:
/**
* \fn void GameObject::Initialize()
* \brief A virtual function that we’ll use as to define how our 
* object is initialized.
*/
  virtual void Initialize() = 0;
/**
* \fn void GameObject::Update(float dt)
* \brief A virtual function that we’ll use as to define how our 
* object is updated.
* \param dt The time in fractions of a second since the last pass.
*/  
  virtual void Update(float dt) = 0;

/**
* \fn void GameObject::Draw(SDL_Renderer *renderer, float dt)
* \brief A virtual function that we’ll use as to define how our 
* object is drawn to the screen.
* \param renderer The SDL renderer used to draw the object.
* \param dt The time in fractions of a second since the last pass.
*/
  virtual void Draw(SDL_Renderer *renderer, float dt) = 0;

  ~GameObject(){}

protected:
	GameObject(){}

  Transform _transform;
  SDL_Texture* _texture;
};