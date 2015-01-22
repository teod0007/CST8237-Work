
using namespace std;


class PosXY
{
	float x,y;
public: 
	PosXY():x(0),y(0){};
	PosXY(float x,float y);
	PosXY(PosXY&);
	~PosXY();
	
	void setXY(float x,float y);
	float& getX();
	float& getY();
};