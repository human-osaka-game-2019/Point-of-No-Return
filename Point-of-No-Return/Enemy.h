#ifndef ENEMY_H_
#define ENEMY_H_

#include "Character.h"
#include "State.h"


//“GƒNƒ‰ƒX
class Enemy :public Character
{
public:
	Enemy();
	~Enemy();

	void Update();
private:

	Enemy(const Enemy&);
	Enemy& operator=(const Enemy&);
	Enemy(const Enemy&&);
	Enemy& operator=(const Enemy&&);

	State state;

	

};


#endif // !ENEMY_H_

