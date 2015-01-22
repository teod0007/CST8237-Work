
using namespace std;


class TimerPool
{
	Uint32 old_time, current_time;
	float ftime;
public:
	TimerPool(); 
	TimerPool(TimerPool&);
	~TimerPool();
	
	Uint32& getOld();
	Uint32& getCurrent();
	float& getDelta();
	void updatePool();
};