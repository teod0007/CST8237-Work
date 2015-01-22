

#include "Player.h"
#include <SDL.h>

struct SDL_Renderer;

Player::Player():GameObject(){}

void Player::Initialize()
{
	_transform.position.x = 100.0f;
	_transform.position.y = 100.0f;
	_transform.rotation.x = 100.0f;
	_transform.rotation.y = 90.0f;
}

void Player::Update(float dt)
{

}

void Player::Draw(SDL_Renderer *renderer, float dt)
{
	SDL_SetRenderDrawColor(renderer, 0,0,0,0);
		
	SDL_RenderDrawLine(renderer,_transform.position.x,_transform.position.y,_transform.rotation.x,_transform.rotation.y);
}

