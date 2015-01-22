using namespace std;


class Projectile
{
	TimerPool* timer;
	PosXY *origin,*shipPos;
	SDL_Renderer* renderer;
	float xVel, yVel, maxTime; 

public:
	Projectile(SDL_Renderer* renderer, TimerPool* timer, PosXY *origin, PosXY *shipPos);
	Projectile(Projectile&);
	~Projectile();

	void render();
	void update();

	PosXY& GetOrigin();
	float getMaxTime();
};