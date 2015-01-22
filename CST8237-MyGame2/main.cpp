#include <iostream>
#include <SDL.h>
#include "TimerPool.h"
#include "PosXY.h"
#include "Field.h"
#include "Projectile.h"
#include "Spaceship.h"
#include "Asteroid.h"
#include "AsteroidGenerator.h"
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>


using namespace std;


int main(int argc, char ** argv)
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	SDL_Init(SDL_INIT_VIDEO); 
	
	SDL_Window *window = SDL_CreateWindow("CST8237 Lab 1", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640,640, SDL_WINDOW_SHOWN);

	SDL_Renderer *renderer = SDL_CreateRenderer(window,-1, SDL_RENDERER_ACCELERATED);
	
	

	int posX=100, posY =100;

	//Set the draw color for the screen clearing
	SDL_SetRenderDrawColor(renderer, 255,255,255,255);

	//Clear the renderer
	SDL_RenderClear(renderer);

	TimerPool *timer = new TimerPool();
	Projectile *projectile = 0;
	Field *field = new Field(renderer);
	Spaceship *ship = new Spaceship(renderer,timer);
	AsteroidGenerator *generator = new AsteroidGenerator(renderer,timer);
	int points=0, lifes=3;

	/*
	TTF_Font* Sans = TTF_OpenFont("Sans.ttf", 24); //this opens a font style and sets a size

	SDL_Color White = {255, 255, 255};  // this is the color in rgb format, maxing out all would give you the color white, and it will be your text's color

	SDL_Surface* surfaceMessage = TTF_RenderText_Solid(Sans, "put your text here", White); // as TTF_RenderText_Solid could only be used on SDL_Surface then you have to create the surface first

	SDL_Texture* Message = SDL_CreateTextureFromSurface(renderer, surfaceMessage); //now you can convert it into a texture

	SDL_Rect Message_rect; //create a rect
	Message_rect.x = 0;  //controls the rect's x coordinate 
	Message_rect.y = 0; // controls the rect's y coordinte
	Message_rect.w = 100; // controls the width of the rect
	Message_rect.h = 100; // controls the height of the rect
	*/
	while(true)
	{
		
		timer->updatePool();
		SDL_SetRenderDrawColor(renderer, 255,255,255,255);

		//Clear the renderer
		SDL_RenderClear(renderer);

		SDL_Event evt;
		
		if(SDL_PollEvent(&evt)){// Check for the quit message
			if (evt.type == SDL_QUIT)
			{
				// Quit the program
				break;
			}

			if (evt.type == SDL_KEYDOWN)
			{
				SDL_Keycode key = evt.key.keysym.sym;
				if (key == SDLK_UP){
					ship->getFw() = true;
					ship->getDw() = false;
					ship->getIsAcc() = true;
				}
				if (key == SDLK_RIGHT)
					ship->getR_r() = true;
				if (key == SDLK_DOWN){
					ship->getFw() = false;
					ship->getDw() = true;
					ship->getIsAcc() = true;
				}
				if (key == SDLK_LEFT)
					ship->getR_l() = true;
				if (key == SDLK_SPACE)
					if(!projectile) projectile = new Projectile(renderer,timer, &ship->GetOrigin(),&ship->GetXY()[0]);
			}

			



		}
		field->render();
		generator->update();

		if(generator->evalShip(ship)){
			delete ship;
			ship = new Spaceship(renderer,timer);
		}

		ship->update();
		//ship->getFw() = false;
		//field->render();
		ship->render();
		
		if(projectile != 0){
			if(projectile->getMaxTime()<=2){
				projectile->update();
				projectile->render();
				if(generator->evalProjectile(projectile)){
					delete projectile;
					projectile = 0;
					points++;
					lifes--;
				}
			}
			else{ 
				delete projectile;
				projectile = 0;
			}
		}
		//Set the draw color of the point
		//SDL_SetRenderDrawColor(renderer, 0,0,0,0);

		//Draw point
		//SDL_RenderDrawPoint(renderer,posX, posY);



		//posY = (posY < 640) ? posY + 1 : posY;
		
		//Show in window
		SDL_RenderPresent(renderer);
		//SDL_RendererFlip(renderer);
	}


	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	system("pause");

	return 0;	
}