﻿#include "MapChip.h"
#include "Main.h"
#include "string"


void DRAWMAP::DrawMapChip(int map_size_width, int map_size_height, float texture_width, float texture_height, float mapchip_width, float mapchip_height, float draw_width, float draw_height, float draw_pos_x, float draw_pos_y, std::string texturename, int** map)
{
	for (int i = 0; i < map_size_height; i++)
	{
		for (int j = 0; j < map_size_width; j++)
		{
			int chip_id = map[i][j];
			if (chip_id == 0)
			{
				continue;
			}

			// テクスチャのサイズとマップチップのサイズから横と縦のチップ数を割り出す
			// (int)g_TextureList[TextureId::MapChip].m_Width       テクスチャのwidth
			//(int)g_TextureList[TextureId::MapChip].m_Height       テクスチャのheight
			//MAPCHIP_WIDTH                                         マップチップの１つのwidth大きさ
			//MAPCHIP_HEIGHT                                        マップチップの１つのheight大きさ
			int width_num = texture_width / mapchip_width;
			int height_num = texture_height / mapchip_height;

			// chip_idからチップのテクスチャ座標を割り出す
			// チップの描画
			//chip_pos_x                                            左上のtuの位置
			//chip_pos_y                                            左上のtvの位置
			//MAPCHIP_WIDTH                                         一マスのwidth大きさ
			//MAPCHIP_HEIGHT                                        一マスのheight大きさ
			float chip_pos_x = (float)(chip_id % width_num) * mapchip_width;
			float chip_pos_y = (float)(chip_id / height_num) * mapchip_height;

			DRAWMAP::TexturePrint(draw_pos_x + draw_width * j, draw_pos_y + draw_height * i, draw_width, draw_height, chip_pos_x / texture_width, chip_pos_y / texture_height, mapchip_width / texture_width, mapchip_height / texture_height, texturename);
		}
	}
}

//マップチップ描画
void DRAWMAP::TexturePrint(int drawpos_x, int drawpos_y, int mapcip_width, int mapchip_height, float chip_pos_x, float chip_pos_y, float width_num, float height_num, std::string texturename)
{
	DirectX& dx = DirectX::GetInstance();

	dx.DrawEx(drawpos_x, drawpos_y, 0, mapcip_width, mapchip_height, 0, 1.f, 0, texturename, chip_pos_x, chip_pos_y, width_num, height_num);
}


void DRAWMAP::InitMap()
{
	for (int i = 0; i < world_size_height; i++)
	{
		for (int j = 0; j < world_size_width; j++)
		{
			if (i == 14 || i == 15)
			{
				map[i][j] = 1;
			}
		}
	}
	for (int i = 0; i < world_size_height; i++)
	{
		map_[i] = map[i];
	}
}



