#include <SDL.h>
#include <math.h>
#include "PosXY.h"
#include "TimerPool.h"
#include "Spaceship.h"

Spaceship::Spaceship(SDL_Renderer* renderer, TimerPool* timer){
	this->timer = timer;
	this->renderer = renderer;
	degrees = 90;
	pos = new PosXY*[3];
	pos[0] = new PosXY(200,200);
	pos[1] = new PosXY(196,204);
	pos[2] = new PosXY(204,204);
	origin = new PosXY(200,201);
	xVel= 0.0f;
	yVel= 0.0f;
	acc = 5.0f;
	isAcc=fw=dw=r_left=r_right=false;
	
}
Spaceship::Spaceship(Spaceship&){}


Spaceship::~Spaceship(){
	if(pos!= 0){
		for(int i = 0; i<3; i++)
			delete pos[i];
		delete pos;
	}
}
void Spaceship::render(){
	SDL_SetRenderDrawColor(renderer, 0,0,0,0);
		
	
		
	SDL_RenderDrawLine(renderer,pos[0]->getX(),pos[0]->getY(),pos[1]->getX(),pos[1]->getY());
		
	SDL_RenderDrawLine(renderer,pos[1]->getX(),pos[1]->getY(),pos[2]->getX(),pos[2]->getY());
	
	SDL_RenderDrawLine(renderer,pos[2]->getX(),pos[2]->getY(),pos[0]->getX(),pos[0]->getY());
		
		//Draw point
		/*for(int y = pos[0]->getY(),x = pos[0]->getX(); y <= pos[1]->getY(),x >= pos[1]->getX(); y++,x--)
			SDL_RenderDrawPoint(renderer, x, y);

		for(int y = pos[0]->getY(),x = pos[0]->getX(); y <= pos[2]->getY(),x <= pos[2]->getX(); y++,x++)
			SDL_RenderDrawPoint(renderer, x, y);

		for(int x = pos[2]->getX(); x >= pos[1]->getX(); x--)
			SDL_RenderDrawPoint(renderer, x,pos[2]->getY());
		*/
	
}

PosXY*& Spaceship::GetXY(){

	return *pos;
}

PosXY& Spaceship::GetOrigin(){

	return *origin;
}


void Spaceship::rotateL(){
	if(r_left){
		rotateP(pos[0], false);
		rotateP(pos[1], false);
		rotateP(pos[2], false);
	}
}

void Spaceship::rotateR(){
	if(r_right){
		rotateP(pos[0], true);
		rotateP(pos[1], true);
		rotateP(pos[2], true);
	}
}

PosXY& Spaceship::rotateP(PosXY *rotated, bool right){
	float degrees = -5;
	if(right) degrees *= -1;
	this->degrees += degrees;
	if(this->degrees < 0) this->degrees = 355;
	if(this->degrees > 360) this->degrees = 5;
	float radians = degrees * 3.14159f/180;
	PosXY *actual = new PosXY(rotated->getX(),rotated->getY());
	
	actual->getX()-=origin->getX();
	actual->getY()-=origin->getY();


	rotated->getX() = (actual->getX() * cos(radians) - actual->getY() * sin(radians));
	rotated->getY() = (actual->getX() * sin(radians) + actual->getY() * cos(radians));

	rotated->getX() += origin->getX();
	rotated->getY() += origin->getY();

	return *rotated;

}

void Spaceship::move(){
   float xMov=0.0f,yMov = 0.0f;
   float delta = timer->getDelta();
   float radians = degrees * 3.14159f/180;

   PosXY *actual = new PosXY(pos[0]->getX()-origin->getX(),pos[0]->getY()-origin->getY());
   radians = atan2f(actual->getX(),actual->getY());
   if(isAcc){
	   if(fw){
		yVel -= acc * cos(radians);
		xVel -= acc * sin(radians); 
	   }
	   if(dw){
	    yVel += acc * cos(radians);
		xVel += acc * sin(radians);
		}
   }
   /*if(fw){
	   xMov += (xVel * delta);
	   yMov += (yVel * delta);
   }else if(dw){
	   xMov -= (xVel * delta);
	   yMov -= (yVel * delta);
   }*/
	   xMov += (xVel * delta);
	   yMov += (yVel * delta);
	   pos[0]->getX()-=(xMov);
	   pos[0]->getY()-=(yMov);
	   pos[1]->getX()-=(xMov);
	   pos[1]->getY()-=(yMov);
	   pos[2]->getX()-=(xMov);
	   pos[2]->getY()-=(yMov);
	   origin->getX()-=(xMov);
	   origin->getY()-=(yMov);
   
}


void Spaceship::update(){
	
	move();
	isAcc = false;
	rotateR();
	rotateL();
	getR_l() = false;
	getR_r() = false;

	if(origin->getX() < 100){
		
		origin->getX() += 400;
		pos[0]->getX() += 400;
		pos[1]->getX() += 400;
		pos[2]->getX() += 400;
	}else
	if(origin->getX() > 500){
		
		origin->getX() -= 400;
		pos[0]->getX() -= 400;
		pos[1]->getX() -= 400;
		pos[2]->getX() -= 400;
	}else
	if(origin->getY() < 100){
		
		origin->getY() += 400;
		pos[0]->getY() += 400;
		pos[1]->getY() += 400;
		pos[2]->getY() += 400;
	}else
	if(origin->getY() > 500){
		
		origin->getY() -= 400;
		pos[0]->getY() -= 400;
		pos[1]->getY() -= 400;
		pos[2]->getY() -= 400;
	}
}

bool& Spaceship::getFw(){
	return fw;
}


bool& Spaceship::getDw(){
	return dw;
}

bool& Spaceship::getR_r(){
	return r_right;
}

bool& Spaceship::getR_l(){
	return r_left;
}

bool& Spaceship::getIsAcc(){
	return isAcc;
}