#ifndef ENDING_H_
#define ENDING_H_

#include "Scene.h"

class Ending : public SceneBase
{

private:
	
public:

	Ending()
	{
		Load();
	}

	~Ending()
	{
		Release();
	}


	void Update();

	void Draw();

	void Release();

	HANDLE CreateLoadThread();

};




#endif // !CHARCTER_H_
