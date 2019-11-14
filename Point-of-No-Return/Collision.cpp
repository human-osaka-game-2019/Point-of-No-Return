#include "Collision.h"
#include "Object.h"
#include <vector>



std::vector<Vec2> Collision::SearchBlock(const Hero& hero,int** map)
{
	Vec2 vec2(0,0);
	std::vector<Vec2>mapdata;

	int row = (hero.x + hero.x_size / 2) / chip_size - 2;
	int col = (hero.y + hero.y_size / 2) / chip_size - 2;

	for (int i = 0; i < 5;i++)
	{
		for (int j = 0;j < 5;j++)
		{
			if (map[col + i][row + j] != 0)
			{
				vec2.x.value = (row + j) * chip_size;
				vec2.y.value = (col + i) * chip_size;
				//mapdata.emplace_back();
				mapdata.push_back(vec2);
			}
		}
	}
	return mapdata;
}



