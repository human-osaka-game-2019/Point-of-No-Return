#ifndef MAPCHIP_H_
#define MAPCHIP_H_


#include<iostream>
#include<stdio.h>

// ãã­ãã¯ã®æ°
const int world_size_width = 480;
const int world_size_height = 17;
// ãããã¦ããã1ã¤ã®å¤§ãã
const int chip_size_ = 64;
// ãã¯ã¹ãã£ã®å¤§ãã
const int texture_width = 256;
const int texture_height = 256;
// åãåã£ãç»åã®å¤§ãã
const int chip_width_num = texture_width / 4;
const int chip_height_num = texture_height / 4;
// æç»ãµã¤ãº
// const int draw_size = 64;

class Mapchip {
public:

	void DrawMapchip(int map_size_width, int map_size_height, float texture_width, float texture_height, float mapchip_width, float mapchip_height, float draw_width, float draw_height, float draw_pos_x, float draw_pos_y, std::string texturename, int** map);

	void TexturePrint(int drawpos_x, int drawpos_y, int mapcip_width, int mapchip_height, float chip_pos_x, float chip_pos_y, float width_num, float height_num, std::string texturename);

	void InitMap();

	int CheckMapNumber(int x, int y, int** map);

	int* map_[world_size_height];

private:
	int map[world_size_height][world_size_width] = {};

};

#endif // !MAPCHIP_H_
