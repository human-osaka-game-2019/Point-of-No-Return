#ifndef HELP_H_
#define HELP_H_

#include "Scene.h"

class Help : public BaseScene
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

	void CreateLoadThread(HANDLE thread);

};


#endif // !CHARCTER_H_
