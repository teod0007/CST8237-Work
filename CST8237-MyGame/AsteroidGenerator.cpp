#include <SDL.h>
#include <math.h>
#include <time.h>
#include <stdlib.h> 
#include "PosXY.h"
#include "TimerPool.h"
#include "Spaceship.h"
#include "Projectile.h"
#include "Asteroid.h"
#include "AsteroidGenerator.h"


using namespace std;



AsteroidGenerator::AsteroidGenerator(SDL_Renderer *renderer, TimerPool* timer){
	this->renderer = renderer;
	this->timer = timer;
	timeTick = 0;
	asteroidList = new Asteroid*[];
	for(int i = 0; i < 5; i++) asteroidList[i] = 0;
}
AsteroidGenerator::AsteroidGenerator(AsteroidGenerator&){}
AsteroidGenerator::~AsteroidGenerator(){}
	
bool AsteroidGenerator::evalProjectile(Projectile* p){
	for(int i = 0; i < 5; i++){
		if(asteroidList[i]!=0){
			if(static_cast<int>(p->GetOrigin().getX()-asteroidList[i]->GetOrigin().getX())<=9 && static_cast<int>(p->GetOrigin().getX()-asteroidList[i]->GetOrigin().getX())>=-9 && static_cast<int>(+p->GetOrigin().getY()-asteroidList[i]->GetOrigin().getY())<=9 && static_cast<int>(+p->GetOrigin().getY()-asteroidList[i]->GetOrigin().getY())>=-9){
				delete asteroidList[i];
				asteroidList[i] = 0; 
				return true;
			}
		}
	}

	return false;
}
bool AsteroidGenerator::evalShip(Spaceship* s){
	for(int i = 0; i < 5; i++){
		if(asteroidList[i]!=0){
			if(static_cast<int>(s->GetOrigin().getX()-asteroidList[i]->GetOrigin().getX())<=9 && static_cast<int>(s->GetOrigin().getX()-asteroidList[i]->GetOrigin().getX())>=-9 && static_cast<int>(+s->GetOrigin().getY()-asteroidList[i]->GetOrigin().getY())<=9 && static_cast<int>(+s->GetOrigin().getY()-asteroidList[i]->GetOrigin().getY())>=-9){
				delete asteroidList[i];
				asteroidList[i] = 0;
				return true;
			}
		}
	}
	return false;
}

void AsteroidGenerator::update(){
	
	if(timeTick >= 3 )
	for(int i = 0; i < 5; i++){
		if(asteroidList[i]==0){
			asteroidList[i] = new Asteroid(renderer,timer);
			break;
		}
		timeTick = 0;
	}
	timeTick += timer->getDelta();

	for(int i = 0; i < 5; i++){
		if(asteroidList[i]!=0){
			asteroidList[i]->update();
			asteroidList[i]->render();
		}
	}
}
