#include <SDL.h>
#include <math.h>
#include "PosXY.h"
#include "TimerPool.h"
#include "Projectile.h"


using namespace std;



Projectile::Projectile(SDL_Renderer* renderer, TimerPool* timer, PosXY* origin, PosXY* shipPos){
	this->renderer = renderer;
	this->timer = timer;
	this->maxTime = 0.0f;
	this->origin = new PosXY(origin->getX(),origin->getY());
	this->shipPos = new PosXY(origin->getX()-shipPos->getX(),origin->getY()-shipPos->getY());
	float radians = atan2f(this->shipPos->getX(),this->shipPos->getY());
	yVel = 100.0f * cos(radians);
	xVel = 100.0f * sin(radians); 
}
Projectile::Projectile(Projectile&){}
Projectile::~Projectile(){
	delete origin;
	delete shipPos;
}
	
void Projectile::render(){
	SDL_SetRenderDrawColor(renderer, 0,0,0,0);
	SDL_RenderDrawPoint(renderer,origin->getX(),origin->getY());
}

void Projectile::update(){
	
   float xMov=0.0f,yMov = 0.0f;
   float delta = timer->getDelta();
   xMov += (xVel * delta);
   yMov += (yVel * delta);
   origin->getX()-=(xMov);
   origin->getY()-=(yMov);
   maxTime += delta;

   if(origin->getX() < 100){
		
		origin->getX() += 400;
		
	}else
	if(origin->getX() > 500){
		
		origin->getX() -= 400;
		
	}else
	if(origin->getY() < 100){
		
		origin->getY() += 400;
		
	}else
	if(origin->getY() > 500){
		
		origin->getY() -= 400;
		
	}

}

PosXY& Projectile::GetOrigin(){
	return *origin;
}

float Projectile::getMaxTime(){
	return maxTime;
}