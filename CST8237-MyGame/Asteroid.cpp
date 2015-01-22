#include <SDL.h>
#include <math.h>
#include <time.h>
#include <stdlib.h> 
#include "PosXY.h"
#include "TimerPool.h"
#include "Asteroid.h"


using namespace std;



Asteroid::Asteroid(SDL_Renderer* renderer, TimerPool* timer){
	this->renderer = renderer;
	this->timer = timer;
	this->origin = new PosXY(500,500);
	srand (SDL_GetTicks()/4);
	int rx = rand() % 500;
	srand (SDL_GetTicks()/2);
	int ry = rand() % 500;
	srand (SDL_GetTicks()/3);
	int rv = rand() % 30;
	if(rv<10) rv = -10;
	float radians = atan2f(rx,ry);
	yVel = rv * cos(radians);
	xVel = rv * sin(radians);
}
Asteroid::Asteroid(Asteroid&){}
Asteroid::~Asteroid(){
	delete origin; 
}
	
void Asteroid::render(){
	SDL_SetRenderDrawColor(renderer, 0,0,0,0);
	for(int i = 0; i < 360; i++)
		SDL_RenderDrawPoint(renderer,origin->getX() + 10 * cos(i*3.14159f/180),origin->getY() + 10 * sin(i*3.14159f/180));
}

void Asteroid::update(){
	
   float xMov=0.0f,yMov = 0.0f;
   float delta = timer->getDelta();
   xMov += (xVel * delta);
   yMov += (yVel * delta);
   origin->getX()-=(xMov);
   origin->getY()-=(yMov);

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

PosXY& Asteroid::GetOrigin(){
	return *origin;
}

