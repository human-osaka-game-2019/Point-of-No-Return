#ifndef ENDING_H_
#define ENDING_H_

#include "Scene.h"

class Ending : public BaseScene
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

	void CreateLoadThread(HANDLE thread);

};




#endif // !CHARCTER_H_
