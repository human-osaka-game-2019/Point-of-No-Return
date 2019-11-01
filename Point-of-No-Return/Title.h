#ifndef TITLE_H_
#define TITLE_H_

#include "Scene.h"

class Title : public SceneBase
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


	void Update();

	void Draw();

	void Release();

	HANDLE CreateLoadThread();

};






#endif // !CHARCTER_H_
