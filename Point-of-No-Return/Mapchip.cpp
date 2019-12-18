#include "MapChip.h"

#include "Character.h"
#include "Main.h"
#include "string"

void Mapchip::DrawMapchip(float draw_start_pos_x, float draw_start_pos_y, std::string texturename, int** map)
{
	int width_num = TEXTURE_WIDTH / CHIP_WIDTH_NUM;
	int height_num = TEXTURE_HEIGHT / CHIP_HEIGHT_NUM;

	float draw_min_position = -CHIP_SIZE;
	float draw_max_position = Display::DISPLAY_WIDTH + CHIP_SIZE;

	for (int i = 0; i < WORLD_SIZE_HEIGHT; i++)
	{
		for (int j = 0; j < WORLD_SIZE_WIDTH; j++)
		{
			int chip_id = map[i][j];
			if (chip_id == 0)
			{
				continue;
			}

			float draw_pos_x = draw_start_pos_x + CHIP_SIZE * j;
			float draw_pos_y = draw_start_pos_y + CHIP_SIZE * i;

			if (draw_pos_x < draw_min_position || draw_max_position < draw_pos_x)
			{
				continue;
			}

			float tu = (float)(chip_id % width_num) * CHIP_WIDTH_NUM / TEXTURE_WIDTH;
			float tv = (float)(chip_id / height_num) * CHIP_HEIGHT_NUM / TEXTURE_HEIGHT;
			TexturePrint(draw_pos_x, draw_pos_y, tu, tv, texturename);
		}
	}
}

//マップチップ描画
void Mapchip::TexturePrint(float drawpos_x, float drawpos_y, float tu, float tv, std::string texturename)
{
	DirectX& dx = DirectX::GetInstance();

	float width = static_cast<float>(CHIP_SIZE);
	float height = static_cast<float>(CHIP_SIZE);

	float tu_width = static_cast<float>(CHIP_WIDTH_NUM) / TEXTURE_WIDTH;
	float tv_height = static_cast<float>(CHIP_HEIGHT_NUM) / TEXTURE_HEIGHT;

	dx.DrawEx(drawpos_x, drawpos_y, 0.f, width, height, 0.f, 1.f, false, texturename, tu, tv, tu_width, tv_height);
}


void Mapchip::InitMap()
{
	//α用のマップ
	for (int i = 0; i < WORLD_SIZE_HEIGHT; i++)
	{
		for (int j = 0; j < WORLD_SIZE_WIDTH; j++)
		{
			if (i == 14 || i == 15)
			{
				map[i][j] = 1;
			}
		}
	}
	
	for (int i = 0; i < WORLD_SIZE_HEIGHT; i++)
	{
		map_[i] = map[i];
	}
}

Matrix Mapchip::CalcMapMatrix(const Position& position, const Position& offset)
{
	int col = (position.x.value + offset.x.value) / CHIP_SIZE;
	int row = (position.y.value + offset.y.value) / CHIP_SIZE;

	Matrix matrix =
	{
		Col(col),
		Row(row)
	};

	return matrix;
}


Position Mapchip::CalcMapPosition(const Matrix& matrix,const Position& offset)
{
	float coordinatex = (matrix.col.value * CHIP_SIZE) - offset.x.value;
	float coordinatey = (matrix.row.value * CHIP_SIZE) - offset.y.value;

	Position position =
	{
		CoordinateX(coordinatex),
		CoordinateY(coordinatey)
	};

	return position;
}
