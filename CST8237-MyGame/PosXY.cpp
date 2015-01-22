
#include "PosXY.h"

	
PosXY::PosXY(float x,float y){
	this->x = x;
	this->y = y;
}
void PosXY::setXY(float x,float y){
	this->x = x;
	this->y = y;
}
PosXY::~PosXY(){}
PosXY::PosXY(PosXY&){}
float& PosXY::getX(){ return x;}
float& PosXY::getY(){ return y;} 