using namespace std;


class AsteroidGenerator
{
	SDL_Renderer *renderer;
	TimerPool* timer; 
	Asteroid** asteroidList;
	float timeTick;

public:
	AsteroidGenerator(SDL_Renderer *renderer, TimerPool* timer);
	AsteroidGenerator(AsteroidGenerator&);
	~AsteroidGenerator();
	bool evalProjectile(Projectile* p);
	bool evalShip(Spaceship* s);
	void update();
};