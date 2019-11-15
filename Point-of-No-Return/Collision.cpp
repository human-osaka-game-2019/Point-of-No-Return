#include "Collision.h"
#include "Object.h"
#include <vector>



std::vector<Vec2> Collision::SearchBlock(const Vec2& vec,const Size& size,int** map)
{
	Vec2 vec2(0,0);
	std::vector<Vec2>mapdata;

	int center_x = vec.x.value + size.width.value / 2;
	int center_y = vec.y.value + size.height.value / 2;

	Matrix search_start = 
	{
		static_cast<Col>(center_x / chip_size - 2),
		static_cast<Row>(center_y / chip_size - 2) 
	};
	
	for (int i = 0; i < 5;i++)
	{
		for (int j = 0;j < 5;j++)
		{
			Matrix current = 
			{
				static_cast<Col>(search_start.col.value + j),
				static_cast<Row>(search_start.row.value + i)
			};

			if (map[current.row.value][current.col.value] != 0)
			{
				vec2.x.value = current.col.value * chip_size;
				vec2.y.value = current.row.value * chip_size;
				mapdata.push_back(vec2);
			}
		}
	}
	return mapdata;
}



