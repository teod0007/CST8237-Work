
#include "GameEngine.h"
#include <SDL.h>
#include <math.h>
#include "CollisionManager.h"
#include "MathUtils.h"
#include "Player.h"
#include "Asteroid.h"
#include "Wall.h"
#include "Projectile.h"
#include <string>
#include <SDL_image.h>


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

  IMG_Init(IMG_INIT_PNG);

  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

  // Using the default member-wise initializer for our new struct.
  _texture = IMG_LoadTexture( renderer, "./ratinho.png");
  const char* error = IMG_GetError();
  
  _walls = new Wall*[6];
  _walls[0] = new Wall(150,150,300,2.0f);
  _walls[1] = new Wall(400,150,300,2.0f);
  _walls[2] = new Wall(50,50,500.0f,2.0f);
  _walls[3] = new Wall(50,50,2.0f,500.0f);
  _walls[4] = new Wall(50,550,2.0f,500.0f);
  _walls[5] = new Wall(550,50,500,2.0f);
  /*
  for(int i = 0; i < 10; i++)
  {
		  _asteroids[i] = nullptr;
  }*/
  _projectiles = new Projectile*[10];
  for(int i = 0; i < 10; i++)
  {
		  _projectiles[i] = nullptr;
  }
  _player1 = new Player();
  _player1->SetPosition(100,100);
  _player1->Initialize();
  
  _player2 = new Player();
  _player2->SetPosition(200,100);
  _player2->Initialize();

  _lives = 3;
  _points1 = _points2 = 0;

  std::string title = "Awesome Game ---- Lives: "+std::to_string (_lives)+"Points: "+std::to_string (_points1);
   
  SDL_SetWindowTitle(window,title.c_str());
  _moveUp1 = _moveDown1 = _rotateLeft1 = _rotateRight1 =_shoot1 =  _moveUp2 = _moveDown2 = _rotateLeft2 = _rotateRight2 =_shoot2 =false;

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
		_moveUp1 = true;
		break;
    case SDLK_DOWN:
		_moveDown1 = true;
		break;
	case SDLK_RIGHT:
		_rotateRight1 = true;
		break;
    case SDLK_LEFT:
		_rotateLeft1 = true;
		break;
	case SDLK_KP_0:
		_shoot1 = true;
		break;
	case SDLK_w:
		_moveUp2 = true;
		break;
    case SDLK_s:
		_moveDown2 = true;
		break;
	case SDLK_d:
		_rotateRight2 = true;
		break;
    case SDLK_a:
		_rotateLeft2 = true;
		break;
	case SDLK_SPACE:
		_shoot2 = true;
		break;
    default:
		break;
    }
  }
  if (evt.type == SDL_KEYUP)
  {

    SDL_KeyboardEvent &keyboardEvt = evt.key;
    SDL_Keycode &keyCode = keyboardEvt.keysym.sym;
    switch (keyCode)
    {
    case SDLK_UP:
		_moveUp1 = false;
		break;
    case SDLK_DOWN:
		_moveDown1 = false;
		break;
	case SDLK_RIGHT:
		_rotateRight1 = false;
		break;
    case SDLK_LEFT:
		_rotateLeft1 = false;
		break;
	case SDLK_KP_0:
		_shoot1 = false;
		break;
	case SDLK_w:
		_moveUp2 = false;
		break;
    case SDLK_s:
		_moveDown2 = false;
		break;
	case SDLK_d:
		_rotateRight2 = false;
		break;
    case SDLK_a:
		_rotateLeft2 = false;
		break;
	case SDLK_KP_SPACE:
		_shoot2 = false;
		break;
    default:
		break;
    }
  }

  if(_moveUp1)
	  _player1->Move(FORWARD);
  if(_moveDown1)
	  _player1->Move(BACKWARD);
  if(_rotateRight1)
	  _player1->Turn(RIGHT,_deltaTime);
  if(_rotateLeft1)
      _player1->Turn(LEFT, _deltaTime);
  if(_shoot1)
	  if(_player1->IsActive() && !_player1->IsDead())
      for(int i = 0; i < 10; i++)
		  if(_projectiles[i] == nullptr)
		  {
			  _projectiles[i] = new Projectile(_player1->GetTransform()); //add a new projectile to the list
			  _projectiles[i]->Initialize();
			  _shoot1 = false;
			  break;
			  
		  }
  if(_moveUp2)
	  _player2->Move(FORWARD);
  if(_moveDown2)
	  _player2->Move(BACKWARD);
  if(_rotateRight2)
	  _player2->Turn(RIGHT,_deltaTime);
  if(_rotateLeft2)
      _player2->Turn(LEFT, _deltaTime);
  if(_shoot2)
      if(_player2->IsActive() && !_player2->IsDead())
	  for(int i = 0; i < 10; i++)
		  if(_projectiles[i] == nullptr)
		  {
			  _projectiles[i] = new Projectile(_player2->GetTransform()); //add a new projectile to the list
			  _projectiles[i]->Initialize();
			  _shoot2 = false;
			  break;
			  
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
  
  //SDL_RenderCopy(renderer, _texture, nullptr,nullptr);
  _player1->Update(_deltaTime);
  _player1->Draw(renderer,_deltaTime);

  _player2->Update(_deltaTime);
  _player2->Draw(renderer,_deltaTime);
  /*
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
  */
  
  //iterates the list and updates/draws each wall
  for(int i = 0; i < 6; i++)
  {
	if(_walls[i] != nullptr)
	{
		_walls[i]->Update(_deltaTime);
		_walls[i]->Draw(renderer,_deltaTime);
	}
  }
  
  //iterates the list and updates/draws each projectile
  for(int i = 0; i < 10; i++)
  {
	if(_projectiles[i] != nullptr)
	{
		_projectiles[i]->Update(_deltaTime);
		_projectiles[i]->Draw(renderer,_deltaTime);
		if(_projectiles[i]->GetBounces()<=0)
		{
			delete _projectiles[i];
			_projectiles[i]=nullptr;
		}
	}
  }
  
  //evaluates the position of each wall in relation to each projectile
  for(int i = 0; i < 6; i++)
  {
		if(_walls[i] != nullptr)
		{
			for(int j = 0; j < 10; j++)
			{
				if(_projectiles[j] != nullptr)
				{
					if(CollisionManager::EvaluateWallProjectile(*_walls[i],*_projectiles[j]))
						break;
				}
			}
		}
	}

  //evaluates the position of each wall in relation to each player
  for(int i = 0; i < 6; i++)
  {
		if(_walls[i] != nullptr)
		{
			if(CollisionManager::EvaluatePlayerWall(*_player1,*_walls[i]) || CollisionManager::EvaluatePlayerWall(*_player2,*_walls[i]))
						break;
		}
  }
  
  for(int j = 0; j < 10; j++)
  {
		if(_projectiles[j] != nullptr)
		{
			if(CollisionManager::EvaluatePlayerProjectile(*_player1,*_projectiles[j]))
			{
				delete _projectiles[j];
				_projectiles[j] = nullptr;
				_player1->DeathRotation();
				_player2->SuspendActions();
				_points2++;
				break;
			}
			if(CollisionManager::EvaluatePlayerProjectile(*_player2,*_projectiles[j]))
			{
				delete _projectiles[j];
				_projectiles[j] = nullptr;
				_player2->DeathRotation();
				_player1->SuspendActions();
				_points1++;
				break;
			}
		}
  }

  if(CollisionManager::EvaluatePlayerPlayer(*_player1,*_player2))
	  ;
  //evaluates the position of each asteroid in relation to the player
  /*
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
  */
 std::string title = "Awesome Game ---- Score :: P1 - "+std::to_string (_points1) + " / P2 - "+std::to_string (_points2);

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