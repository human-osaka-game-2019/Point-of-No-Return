#ifndef HELP_H_
#define HELP_H_

#include "Scene.h"

class Help : public SceneBase
{
public:

	Help()
	{
		Load();
	}

	~Help()
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
