#ifndef TITLE_H_
#define TITLE_H_

#include "Scene.h"

class Title : public BaseScene
{
public:

	Title()
	{
		Load();
	}

	~Title()
	{
		Release();
	}


	void Load();

	void Update();

	void Draw();

	void Release();

	HANDLE CreateLoadThread();

};






#endif // !CHARCTER_H_
