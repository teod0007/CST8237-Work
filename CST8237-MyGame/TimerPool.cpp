#include <SDL.h>
#include "TimerPool.h"


using namespace std;



TimerPool::TimerPool(){
	old_time = current_time = SDL_GetTicks();
	ftime = 0.0f;
}
TimerPool::TimerPool(TimerPool&){}
TimerPool::~TimerPool(){}
	
Uint32& TimerPool::getOld(){
	return old_time;
}
Uint32& TimerPool::getCurrent(){ 
	return current_time;
}
float& TimerPool::getDelta(){
	if(ftime == 0.0f) updatePool();
	return ftime;
}

void TimerPool::updatePool(){
	old_time = current_time;
	current_time = SDL_GetTicks();
	ftime = (current_time - old_time) / 1000.0f;
}
