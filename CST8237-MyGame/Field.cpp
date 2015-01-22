#include <SDL.h>

#include "PosXY.h"
#include "Field.h"


Field::Field(SDL_Renderer* renderer){
	
	this->renderer = renderer;
	pos = new PosXY*[4];
	pos[0] = new PosXY(100,100);
	pos[1] = new PosXY(100,500);
	pos[2] = new PosXY(500,100);
	pos[3] = new PosXY(500,500);
	
}
Field::Field(PosXY** pos, SDL_Renderer* renderer){}
Field::Field(Field&){}


Field::~Field(){
	if(pos!= 0){
		for(int i = 0; i<4; i++)
			delete pos[i];
		delete pos;
	}
}
void Field::render(){
	SDL_SetRenderDrawColor(renderer, 0,0,0,0);
		//Draw point
		for(int y = pos[0]->getY(); y <= pos[1]->getY(); y++)
			SDL_RenderDrawPoint(renderer,pos[0]->getX(), y);

		for(int x = pos[0]->getX(); x <= pos[2]->getX(); x++)
			SDL_RenderDrawPoint(renderer, x,pos[0]->getY()); 

		for(int x = pos[3]->getX(); x >= pos[1]->getX(); x--)
			SDL_RenderDrawPoint(renderer, x,pos[3]->getY());

		for(int y = pos[3]->getY(); y >= pos[2]->getY(); y--)
			SDL_RenderDrawPoint(renderer,pos[3]->getX(), y);
	
	
}

PosXY*& Field::GetXY(){

	return *pos;
}
