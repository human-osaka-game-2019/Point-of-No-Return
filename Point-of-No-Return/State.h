#ifndef STATE_H_
#define STATE_H_

#include "Enemy.h"

class State
{
public:
	State(Vec2 &enemy_pos);
	~State();

	void Search(Vec2 pos);

private:

	Vec2 enemy_pos;

};


class Stay :public State
{
public:
	Stay();
	~Stay();

private:


};

class Chase : public State
{
public:
	Chase();
	~Chase();

private:



};

#endif // !STATE_H_

