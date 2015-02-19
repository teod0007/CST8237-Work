#include "MathUtils.h"
#include <math.h>

float MathUtils::ToDegrees(float radians)
{
  float radiansToDegrees = 180.0f / 3.1415926535f;
  return radians * radiansToDegrees;
}

float MathUtils::ToRadians(float degrees)
{
  float degreesToRadians = 3.1415926535f / 180.0f;
  return degrees * degreesToRadians;
}

Vector2 MathUtils::Rotate(Vector2 &rotated,Vector3 &origin, Direction d,float dt)
{
	float degrees = -60;
	if(d == RIGHT) degrees *= -1;
	origin.z += degrees;
	if(origin.z < 0) origin.z = 360 + degrees;
	if(origin.z > 360) origin.z = -degrees;
	float radians = ToRadians(degrees*dt);
	Vector2 actual = { rotated.x,rotated.y};
	
	actual.x-=origin.x;
	actual.y-=origin.y;


	rotated.x = (actual.x * cos(radians) - actual.y * sin(radians));
	rotated.y = (actual.x * sin(radians) + actual.y * cos(radians));

	rotated.x += origin.x;
	rotated.y += origin.y;

	return rotated;

}

float MathUtils::AtanF(float x, float y)
{
	return atan2f(x,y);
}

float MathUtils::VectorDecomposition(float acceleration, float radians,VectorAxis a)
{
	if(a == Y)
		return acceleration * cos(radians);
	else
		return acceleration * sin(radians);
}