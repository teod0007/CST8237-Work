#include "CollisionManager.h"


bool CollisionManager::EvaluatePlayerPlayer(Player& p1, Player& p2)
{
	if((p1.GetPosition().x - p2.GetPosition().x < 5 && p1.GetPosition().y - p2.GetPosition().y < 5) && (p1.GetPosition().x - p2.GetPosition().x > -5 && p1.GetPosition().y - p2.GetPosition().y > -5))
	{
		if(p1.GetPosition().x < p2.GetPosition().x)
		{
			p1.AddPositionX(-4);
			p2.AddPositionX(4);
		}
		else if(p1.GetPosition().x > p2.GetPosition().x)
		{
			p1.AddPositionX(4);
			p2.AddPositionX(-4);
		}
		else if(p1.GetPosition().x - p2.GetPosition().x > 0 && p1.GetPosition().y - p2.GetPosition().y > 0)
		{
			
		}
		else if(p1.GetPosition().x - p2.GetPosition().x < 0 && p1.GetPosition().y - p2.GetPosition().y < 0)
		{
			
		}
		return true;
	}
	return false;
}
bool CollisionManager::EvaluatePlayerProjectile(Player& player, Projectile& proj)
{
	if((player.GetPosition().x - proj.GetPosition().x < 3 && player.GetPosition().y - proj.GetPosition().y < 3) && (player.GetPosition().x - proj.GetPosition().x > -3 && player.GetPosition().y - proj.GetPosition().y > -3))
	{
		return true;
	}
	return false;
}
bool CollisionManager::EvaluatePlayerWall(Player& player, Wall& wall)
{
	if((wall.GetPosition().x < player.GetPosition().x && (wall.GetPosition().x + wall.GetPosition().w) > player.GetPosition().x) && (wall.GetPosition().y < player.GetPosition().y && (wall.GetPosition().y + wall.GetPosition().h) > player.GetPosition().y))
	{
		if((player.GetPosition().x - wall.GetPosition().x) < (player.GetPosition().y - wall.GetPosition().y) || (player.GetPosition().x - wall.GetPosition().x) < (- player.GetPosition().y + wall.GetPosition().y +  wall.GetPosition().h)
			|| (- player.GetPosition().x + wall.GetPosition().x + wall.GetPosition().w ) < (player.GetPosition().y - wall.GetPosition().y) || (- player.GetPosition().x + wall.GetPosition().x + wall.GetPosition().w ) < (- player.GetPosition().y + wall.GetPosition().y + wall.GetPosition().h) )
		{
			if((player.GetPosition().x - wall.GetPosition().x) < (- player.GetPosition().x + wall.GetPosition().x + wall.GetPosition().w))
			{
				player.AddPositionX( -( player.GetTransform().rotation.x - wall.GetPosition().x + 5 ));
				//proj.ReverseX();
			}
			else if((player.GetPosition().x - wall.GetPosition().x) > (- player.GetPosition().x + wall.GetPosition().x + wall.GetPosition().w))
			{
				player.AddPositionX( +( player.GetTransform().rotation.x - wall.GetPosition().x + 5 ));
				//proj.ReverseX();
			}
			
			
		}
		else
		{
			if((player.GetPosition().y - wall.GetPosition().y) < (- player.GetPosition().y + wall.GetPosition().y + wall.GetPosition().h))
			{
				player.AddPositionY( -( player.GetTransform().rotation.y - wall.GetPosition().y + 5 ));
				//proj.ReverseY();
			}
			else if((player.GetPosition().y - wall.GetPosition().y) > (- player.GetPosition().y + wall.GetPosition().y + wall.GetPosition().h))
			{
				player.AddPositionY( +( player.GetTransform().rotation.y - wall.GetPosition().y + 5 ));
				//proj.ReverseY();
			}
		
		}
		return true;
	}
	return false;
}
bool CollisionManager::EvaluateWallProjectile(Wall& wall, Projectile& proj)
{
	if((wall.GetPosition().x < proj.GetPosition().x && (wall.GetPosition().x + wall.GetPosition().w) > proj.GetPosition().x) && (wall.GetPosition().y < proj.GetPosition().y && (wall.GetPosition().y + wall.GetPosition().h) > proj.GetPosition().y))
	{
		if((proj.GetPosition().x - wall.GetPosition().x) < (proj.GetPosition().y - wall.GetPosition().y) || (proj.GetPosition().x - wall.GetPosition().x) < (- proj.GetPosition().y + wall.GetPosition().y +  wall.GetPosition().h)
			|| (- proj.GetPosition().x + wall.GetPosition().x + wall.GetPosition().w ) < (proj.GetPosition().y - wall.GetPosition().y) || (- proj.GetPosition().x + wall.GetPosition().x + wall.GetPosition().w ) < (- proj.GetPosition().y + wall.GetPosition().y + wall.GetPosition().h) )
		{
			if((proj.GetPosition().x - wall.GetPosition().x) < (- proj.GetPosition().x + wall.GetPosition().x + wall.GetPosition().w))
			{
				proj.GetPosition().x -= proj.GetPosition().x - wall.GetPosition().x;
				proj.ReverseX();
			}
			else if((proj.GetPosition().x - wall.GetPosition().x) > (- proj.GetPosition().x + wall.GetPosition().x + wall.GetPosition().w))
			{
				proj.GetPosition().x += proj.GetPosition().x - wall.GetPosition().x;
				proj.ReverseX();
			}
			
			
		}
		else
		{
			if((proj.GetPosition().y - wall.GetPosition().y) < (- proj.GetPosition().y + wall.GetPosition().y + wall.GetPosition().h))
			{
				proj.GetPosition().y -= proj.GetPosition().y - wall.GetPosition().y;
				proj.ReverseY();
			}
			else if((proj.GetPosition().y - wall.GetPosition().y) > (- proj.GetPosition().y + wall.GetPosition().y + wall.GetPosition().h))
			{
				proj.GetPosition().y += proj.GetPosition().y - wall.GetPosition().y;
				proj.ReverseY();
			}
		
		}
		proj.GetBounces()--;
		return true;
	}
	return false;
}