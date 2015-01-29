#pragma once // Preprocessor directive to ensure that this header will only be included once. -- Generally used on Windows

// Preprocessor directive to ensure that this header will only be included once. -- Generally used for all environments.
/*#ifndef _GAME_ENGINE_H_
#define _GAME_ENGINE_H_

#endif // _GAME_ENGINE_H_*/
#include "MathUtils.h"
// Forward declaring our renderer and window.
// Because we're using them as pointers, we don't need to know their size
// at compile time to define this class.
struct SDL_Renderer;
struct SDL_Window;
class Projectile;
class Player;
class Asteroid;

/**
* \class GameEngine.h
* \brief A class that represents a single object that 
* will controll the game itself.
* \author Emanuel Teodoro Sousa
* \date January 20, 2015
*/
class GameEngine
{
public:
/**
* \fn GameEngine* GameEngine::CreateInstance()
* \brief If our instance is not created already, this
* function will be called to create it.
*/
  static GameEngine* CreateInstance();
/**
* \fn void GameEngine::Initialize()
* \brief A function that we値l use as to define how our 
* object is initialized.
*/
  void Initialize();
/**
* \fn void GameEngine::Shutdown()
* \brief A virtual function that we値l use as to define how our 
* object is shutdown.
*/
  void Shutdown();
/**
* \fn void GameEngine::Update()
* \brief A virtual function that we値l use as to define how our 
* object is updated.
*/
  bool Update();
/**
* \fn bool GameEngine::Draw()
* \brief A virtual function that we値l use as to define how our 
* object is draw on the screen.
*/
  void Draw();

  ~GameEngine();

protected:
  GameEngine();

  static GameEngine *_instance;

  SDL_Window *window;
  SDL_Renderer *renderer;

  // Using the default member-wise initializer for our new struct.
  Player *_ship;
  Asteroid **_asteroids;
  Projectile **_projectiles;
  float _oldTime, _currentTime, _deltaTime, _accumulatedTime;
  int _lives,_points;
};