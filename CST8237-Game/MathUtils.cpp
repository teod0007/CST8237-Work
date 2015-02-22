#include "MathUtils.h"
#include <math.h>

double MathUtils::ToDegrees(float radians)
{
  float radiansToDegrees = 180.0f / 3.1415926535f;
  return radians * radiansToDegrees;
}

double MathUtils::ToRadians(float degrees)
{
  float degreesToRadians = 3.1415926535f / 180.0f;
  return degrees * degreesToRadians;
}

Vector2 MathUtils::Rotate(Vector2 &rotated,Vector3 &origin, Direction d,float dt)
{
	double degrees = -60*dt;
	if(d == RIGHT) degrees *= -1;
	origin.z += degrees/3;
	if(origin.z < -180) origin.z = 360 + origin.z;
	if(origin.z > 180) origin.z = origin.z - 360;
	double radians = ToRadians(degrees);
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