#pragma once

#include "Player.h"
#include "Projectile.h"
#include "Wall.h"

/**
* \class Game.h
* \brief A class that represents a single object that 
* will create the game engine afterwards.
* \author Emanuel Teodoro Sousa
* \date January 20, 2015
*/

class CollisionManager
{
public:
  static bool EvaluatePlayerPlayer(Player& player1, Player& player2);
  static bool EvaluatePlayerProjectile(Player& player, Projectile& proj);
  static bool EvaluatePlayerWall(Player& player, Wall& wall);
  static bool EvaluateWallProjectile(Wall& wall, Projectile& proj);
  
};