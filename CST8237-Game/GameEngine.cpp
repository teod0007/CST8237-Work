
#include "GameEngine.h"
#include <SDL.h>
#include <math.h>
#include "MathUtils.h"
#include "Player.h"
#include "Asteroid.h"
#include "Projectile.h"
#include <string>


GameEngine::GameEngine()
{

}

GameEngine::~GameEngine()
{

}

void GameEngine::Initialize()
{
  SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER);

  window = SDL_CreateWindow("CST8237 Lab",
    SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
    640, 640,
    SDL_WINDOW_SHOWN);
  //SDL_SetWindowTitle(window,"");

  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

  // Using the default member-wise initializer for our new struct.
  
  _asteroids = new Asteroid*[10];
  for(int i = 0; i < 10; i++)
  {
		  _asteroids[i] = nullptr;
  }
  _projectiles = new Projectile*[10];
  for(int i = 0; i < 10; i++)
  {
		  _projectiles[i] = nullptr;
  }
  _ship = new Player();
  _ship->Initialize();

  _lives = 3;
  _points = 0;

  std::string title = "Awesome Game ---- Lives: "+std::to_string (_lives)+"Points: "+std::to_string (_points);

  SDL_SetWindowTitle(window,title.c_str());

  /* Get the time at the beginning of our game loop so that we can track the
  * elapsed difference. */
  _oldTime = SDL_GetTicks();
  _currentTime = _oldTime;
  _accumulatedTime = _oldTime;
}

void GameEngine::Shutdown()
{
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
}

bool GameEngine::Update()
{
  SDL_Event evt;
  SDL_PollEvent(&evt);

  // Calculating the time difference since our last loop.
  _oldTime = _currentTime;
  _currentTime = SDL_GetTicks();
  _deltaTime = (_currentTime - _oldTime) / 1000;
  
  if (evt.type == SDL_QUIT)
  {
	return false;
  }
  // Check for user input.
  if (evt.type == SDL_KEYDOWN)
  {

    SDL_KeyboardEvent &keyboardEvt = evt.key;
    SDL_Keycode &keyCode = keyboardEvt.keysym.sym;
    switch (keyCode)
    {
    case SDLK_UP:
	  _ship->Move(FORWARD);
      break;
    case SDLK_DOWN:
	  _ship->Move(BACKWARD);
      break;
	case SDLK_RIGHT:
	  _ship->Turn(RIGHT);
      break;
    case SDLK_LEFT:
      _ship->Turn(LEFT);
      break;
	case SDLK_SPACE:
      for(int i = 0; i < 10; i++)
		  if(_projectiles[i] == nullptr)
		  {
			  _projectiles[i] = new Projectile(_ship->GetTransform()); //add a new projectile to the list
			  _projectiles[i]->Initialize();
			  break;
			  
		  }
      break;
    default:
      break;
    }
  }
  return true;
}

void GameEngine::Draw()
{
  // Set the draw colour for screen clearing.
  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

  // Clear the renderer with the current draw colour.
  SDL_RenderClear(renderer);

  // Set the draw colour for our point.
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);

  _ship->Update(_deltaTime);
  _ship->Draw(renderer,_deltaTime);

  //iterates the list and creates one asteroid at time, with a limit of 10
  if(static_cast<int>(_accumulatedTime)%6 >=4)
  {
	  for(int i = 0; i < 10; i++)
	  {
		  if(_asteroids[i]== nullptr)
		  {
				_asteroids[i] = new Asteroid();
				_asteroids[i]->Initialize();
				break;
		  }
	  }
	  _accumulatedTime = 0;
  }
  _accumulatedTime+=_deltaTime;

  //iterates the list and updates/draws each asteroid
  for(int i = 0; i < 10; i++)
  {
	if(_asteroids[i] != nullptr)
	{
		_asteroids[i]->Update(_deltaTime);
		_asteroids[i]->Draw(renderer,_deltaTime);
	}
  }
  //iterates the list and updates/draws each projectile
  for(int i = 0; i < 10; i++)
  {
	if(_projectiles[i] != nullptr)
	{
		_projectiles[i]->Update(_deltaTime);
		_projectiles[i]->Draw(renderer,_deltaTime);
		if(_projectiles[i]->GetMaxTime()>3)
		{
			delete _projectiles[i];
			_projectiles[i]=nullptr;
		}
	}
  }

  //evaluates the position of each asteroid in relation to each projectile
  for(int i = 0; i < 10; i++)
  {
		if(_asteroids[i] != nullptr)
		{
			for(int j = 0; j < 10; j++)
			{
				if(_projectiles[j] != nullptr)
				{
					if(static_cast<int>(_projectiles[j]->GetPosition().x-_asteroids[i]->GetPosition().x)<=9 && static_cast<int>(_projectiles[j]->GetPosition().x-_asteroids[i]->GetPosition().x)>=-9 && static_cast<int>(+_projectiles[j]->GetPosition().y-_asteroids[i]->GetPosition().y)<=9 && static_cast<int>(+_projectiles[j]->GetPosition().y-_asteroids[i]->GetPosition().y)>=-9)
					{
						delete _asteroids[i];
						delete _projectiles[j];
						_asteroids[i] = nullptr; 
						_projectiles[j] = nullptr;
						_points++;
						break;
					}
				}
			}
		}
	}
  //evaluates the position of each asteroid in relation to the player
  for(int i = 0; i < 10; i++)
  {
		if(_asteroids[i] != nullptr)
		{
			if(static_cast<int>(_ship->GetPosition().x-_asteroids[i]->GetPosition().x)<=9 && static_cast<int>(_ship->GetPosition().x-_asteroids[i]->GetPosition().x)>=-9 && static_cast<int>(+_ship->GetPosition().y-_asteroids[i]->GetPosition().y)<=9 && static_cast<int>(+_ship->GetPosition().y-_asteroids[i]->GetPosition().y)>=-9)
					{
						if(_lives == 0)
						{
							delete _ship;
							for(int j = 0; j < 10; j++)
							{
								delete _asteroids[j];
								_asteroids[j] = nullptr;
							
							}
							_ship = new Player(); 
							_ship->Initialize();
							_lives = 3;
							_points = 0;
							break;
						}else
						{
							delete _asteroids[i];
							_asteroids[i] = nullptr;
							_lives--;
							break;
						}
					}
		}
  }

 std::string title = "Awesome Game ---- Lives: "+std::to_string (_lives)+" Points: "+std::to_string (_points);

  SDL_SetWindowTitle(window,title.c_str());
  // Draw the point.
  //SDL_RenderDrawPoint(renderer, posX, posY);

  /*static float rotationDegrees = 10.0f;
  rotationDegrees += (rotationSpeed * deltaTime);
  rotationDegrees += (rotationDegrees >= 360.0f ? -360.0f : 0);

  float rotationRadians = MathUtils::ToRadians(rotationDegrees);

  Vector2 rotatedOffset =
  {
    endPointOffset.x * cosf(rotationRadians) + endPointOffset.y * sinf(rotationRadians),
    endPointOffset.x * sinf(rotationRadians) - endPointOffset.y * cosf(rotationRadians)
  };

  Vector2 transformedEndPoint = { pos.x + rotatedOffset.x, pos.y + rotatedOffset.y };

  SDL_RenderDrawLine(renderer, pos.x, pos.y, transformedEndPoint.x, transformedEndPoint.y);
  */
  // Present what is in our renderer to our window.
  SDL_RenderPresent(renderer);
}