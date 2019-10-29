#ifndef GAME_H_
#define GAME_H_

#include "Scene.h"

class Game : public BaseScene
{
public:
	Game()
	{
		Load();
	};

	~Game()
	{
		Release();
	};



	void Load();

	void Update();

	void Draw();

	void Release();

	HANDLE CreateLoadThread();

};



#endif // !CHARCTER_H_
