#ifndef ENDING_H_
#define ENDING_H_

#include "Scene.h"

class Ending : public BaseScene
{

private:
	
public:

	Ending()
	{
		void Load();
	}

	~Ending()
	{
		void Release();
	}

	void Load();

	void Update();

	void Draw();

	void Release();

	void CreateLoadThread(HANDLE thread);

};




#endif // !CHARCTER_H_
