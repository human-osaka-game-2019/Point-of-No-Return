?¿#ifndef MAPCHIP_H_
#define MAPCHIP_H_


#include<iostream>
#include<stdio.h>

const int world_size_width_pos = 480;
const int world_size_height_pos = 16;
const int chip_size_ = 64;

const int texture_width = 256;
const int texture_height = 256;
const int chip_width_num = 256.f/5;
const int chip_height_num = 256.f/5;
const int draw_size = 64;


class DrawMap {
public:

	void DrawMapChip(int map_size_width, int map_size_height, float texture_width, float texture_height, float mapchip_width, float mapchip_height, float draw_width, float draw_height, float draw_pos_x, float draw_pos_y, int texture, int** map);

	void TexturePrint(int drawpos_x, int drawpos_y, int mapcip_width, int mapchip_height, float chip_pos_x, float chip_pos_y, float width_num, float height_num);

	int map[world_size_width_pos][world_size_height_pos] = {};

};

#endif // !CHARCTER_H_
