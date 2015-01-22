/*
mVariable -> member var
kVariable -> static var

---------------------------------

variable -> public
_variable -> private / protected

---------------------------------

m_Variable -> basic type
p_Variable


*/

#pragma once

class GameEngine
{
public:
	static GameEngine* CreateInstance();
	
	GameEngine();
	~GameEngine();

	void Initialize();
	void Shutdown();

	void Update();
	void Draw();

	
	
protected:

};