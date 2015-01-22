
using namespace std;


class Spaceship
{
	PosXY **pos,*origin;
	int degrees;
	SDL_Renderer* renderer;
	TimerPool* timer; 
	bool fw,dw,r_left,r_right,isAcc;
	//float x, y;
	float xVel, yVel, acc;
public:
	Spaceship(SDL_Renderer* renderer, TimerPool* timer);
	Spaceship(Spaceship&);
	~Spaceship();
	
	void render();
	void rotateL();
	void rotateR();
	PosXY& rotateP(PosXY* rotated,  bool right);
	void move();
	void shot();
	void update();
	bool& getDw();
	bool& getFw();
	bool& getR_r();
	bool& getR_l();
	bool& getIsAcc();
	PosXY*& GetXY();
	PosXY& GetOrigin();
};