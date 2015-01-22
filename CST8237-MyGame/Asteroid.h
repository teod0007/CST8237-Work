using namespace std;


class Asteroid
{
	SDL_Renderer *renderer;
	TimerPool* timer;
	PosXY* origin; 
	float xVel,yVel;

public:
	Asteroid(SDL_Renderer *renderer, TimerPool* timer);
	Asteroid(Asteroid&);
	~Asteroid();
	void update();
	void render();
	PosXY& GetOrigin();
};