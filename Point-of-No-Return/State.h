#ifndef STATE_H_
#define STATE_H_

#include "Object.h"
//å„Ç≈ï ÇÃÇ‡ÇÃÇ…èëÇ´ä∑Ç¶ÇÈ
struct SearchArea
{
	int left;
	int right;
	int top;
	int bottom;
	int width;
	int height;

};

class State
{
public:

	State();
	State(Vec2 &enemy_pos, const Size enemy_size);
	~State();


protected:

	bool Search(Vec2& player_pos, IsReverse& is_reverse);
	SearchArea search = {0,0,0,0,0,0};
	Vec2 enemy_pos = {0,0};
	Size enemy_size = {0,0};

};


class Stay :public State
{
public:
	Stay(Vec2& enemy_pos, const Size enemy_size);
	~Stay();


private:

	


};

class Chase : public State
{
public:
	Chase(Vec2& enemy_pos, const Size enemy_size);
	~Chase();


private:

	
};

#endif // !STATE_H_

