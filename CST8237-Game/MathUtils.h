#pragma once


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
  static float ToRadians(float degrees);
  static float ToDegrees(float radians);
  static Vector2 Rotate(Vector2&,Vector3&, Direction d);
  static float AtanF(float x, float y);
  static float VectorDecomposition(float acceleration, float radians,VectorAxis a);
};