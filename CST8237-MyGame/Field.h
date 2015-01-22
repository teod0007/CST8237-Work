
using namespace std;


class Field
{
	SDL_Renderer *renderer;
	PosXY **pos; 
public:
	Field(SDL_Renderer *renderer);
	Field(PosXY **pos,SDL_Renderer *renderer);
	Field(Field&);
	~Field();
	void render();
	PosXY*& GetXY();
};