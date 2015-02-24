#pragma once

#include "Player.h"
#include "Projectile.h"
#include "Wall.h"

/**
* \class CollisionManager.h
* \brief A class that will be used to deal 
* with collisions.
* \author Emanuel Teodoro Sousa
* \date February 20, 2015
*/

class CollisionManager
{
public:
/**
* \fn bool CollisionManager::EvaluatePlayerPlayer(Player&, Player&)
* \brief A static function that we値l use to evaluate the collision
* between player1 and player2
* \param player1 A Player object.
* \param player2 A Player object.
*/
  static bool EvaluatePlayerPlayer(Player& player1, Player& player2);
/**
* \fn bool CollisionManager::EvaluatePlayerProjectile(Player&, Projectile&)
* \brief A static function that we値l use to evaluate the collision
* between player and projectile.
* \param player A Player object.
* \param proj A Projectile object.
*/
  static bool EvaluatePlayerProjectile(Player& player, Projectile& proj);
/**
* \fn bool CollisionManager::EvaluatePlayerProjectile(Player&, Wall&)
* \brief A static function that we値l use to evaluate the collision
* between player and wall.
* \param player A Player object.
* \param wall A Wall object.
*/
  static bool EvaluatePlayerWall(Player& player, Wall& wall);
/**
* \fn bool CollisionManager::EvaluateWallProjectile(Wall&, Projectile&)
* \brief A static function that we値l use to evaluate the collision
* between player and wall.
* \param wall A Wall object.
* \param proj A Projectile object.
*/
  static bool EvaluateWallProjectile(Wall& wall, Projectile& proj);
  
};