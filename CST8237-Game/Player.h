#pragma once
#include "GameObject.h"

/**
* \class Player.h
* \brief A class that represents the object player 
* in the game.
* \author Emanuel Teodoro Sousa
* \date January 20, 2015
*/

class Player: public GameObject
{
	Vector2 _pos1,_pos2;
	float _xVelocity,_yVelocity,_acceleration, _deadTime, _inactiveTime;
	Acceleration _accDirection;
	bool _isDead,_isActive;
public:
	 
	 Player();
/**
* \fn void Player::Initialize()
* \brief A function that we値l use as to define how our 
* object is initialized.
*/
	 virtual void Initialize();
/**
* \fn void Player::Update(float dt)
* \brief A virtual function that we値l use as to define how our 
* object is updated.
* \param dt The time in fractions of a second since the last pass.
*/ 
	 virtual void Update(float dt);
/**
* \fn void Player::Draw(SDL_Renderer *renderer, float dt)
* \brief A virtual function that we値l use as to define how our 
* object is drawn to the screen.
* \param renderer The SDL renderer used to draw the object.
* \param dt The time in fractions of a second since the last pass.
*/
	 virtual void Draw(SDL_Renderer *renderer, float dt);
/**
* \fn void Player::Move(Acceleration)
* \brief A function that we値l use to set
* the direction of acceleration
* \param Acceleration FORWARD or BACKWARD
*/
	 void Move(Acceleration);
/**
* \fn void Player::Turn(Acceleration)
* \brief A function that we値l use to set
* the direction of turning
* \param Direction RIGHT or LEFT
*/
	 void Turn(Direction, float dt);
/**
* \fn Transform& Player::GetTransform()
* \brief A function that we値l use to get
* the Transform component of the player.
*/
	 Transform& GetTransform();
/**
* \fn Vector3& Player::GetPosition()
* \brief A function that we値l use to get
* the Vector3 component inside _transform.
*/
	 Vector3& GetPosition();
/**
* \fn void Player::AddPositionX()
* \brief A function that we値l use to update
* the general position X of player.
*/
	 void AddPositionX(float x);
/**
* \fn void Player::AddPositionY()
* \brief A function that we値l use to update
* the general position Y of player.
*/
	 void AddPositionY(float y);
/**
* \fn void Player::SetPosition()
* \brief A function that we値l use to set
* the general position X,Y of player.
*/
	 void SetPosition(float x, float y);
/**
* \fn void Player::SuspendActions()
* \brief A function that we値l use to suspend
* the relevant actions.
*/
	 void SuspendActions();
/**
* \fn void Player::DeathRotation()
* \brief A function that we値l use to activate
* the death rotation animation.
*/
	 void DeathRotation();
/**
* \fn void Player::IsActive()
* \brief A function that we値l use to get
* the present active state of the player
*/
	 bool IsActive();
/**
* \fn void Player::IsDead()
* \brief A function that we値l use to get
* the present death state of the player
*/
	 bool IsDead();
};