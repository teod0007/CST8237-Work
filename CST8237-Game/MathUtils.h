#pragma once
/**
* \class MathUtils.h
* \brief A class that helps with various structs and enums, 
* as well as functions.
* \author Emanuel Teodoro Sousa
* \date January 20, 2015
*/

enum Direction {RIGHT,LEFT};
enum Acceleration {FORWARD,BACKWARD,NONE};
enum VectorAxis {X,Y};
// A structure to hold two floats. Similar to SDL_Point (though it contains ints).

struct Vector2
{
  float x;
  float y;
};

struct Vector3
{
  float x;
  float y;
  float z;
};

struct Vector4
{
  float x;
  float y;
  float z;
  float w;
};

struct Transform
{
  Vector2 position;
  Vector3 rotation;
  Vector2 scale;
};

class MathUtils
{
public:
/**
* \fn void MathUtils::ToRadians(float degrees)
* \brief A static function that we値l use to make degrees into
* radians
* \param degrees The value in degrees.
*/
  static float ToRadians(float degrees);
/**
* \fn void MathUtils::ToDegrees(float radians)
* \brief A static function that we値l use to make radians into
* degrees
* \param radians The value in radians.
*/
  static float ToDegrees(float radians);
/**
* \fn Vector2 MathUtils::Rotate(Vector2& rotated,Vector3& rotation, Direction d)
* \brief A static function that we値l use to rotate a point around an axis.
* \param rotated Point to be rotated
* \param rotation Axis point
* \param d Direction of the rotation
*/
  static Vector2 Rotate(Vector2&,Vector3&, Direction d);
/**
* \fn float MathUtils::AfanF(float x, float y)
* \brief A static function that we値l use to get the arctanget value of a point.
* \param x X value of the point
* \param y Y value of the point
*/
  static float AtanF(float x, float y);//arctangent 
/**
* \fn float MathUtils::VectorDecomposition(float acceleration, float radians, VectorAxis a)
* \brief A static function that we値l use to get the decomposed value of the acceleration
* on each axis.
* \param acceleration Value of the acceleration in m/s2.
* \param radians Value of the angle in radians.
* \param a Which axis (x or y) to decompose.
*/
  static float VectorDecomposition(float acceleration, float radians,VectorAxis a);
};