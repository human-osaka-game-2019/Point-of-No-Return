﻿#ifndef MAPCHIP_H_
#define MAPCHIP_H_


#include<iostream>
#include<stdio.h>

// ブロックの数
const int world_size_width = 480;
const int world_size_height = 16;
// マップてチップ1つの大きさ
const int chip_size_ = 64;
// テクスチャの大きさ
const int texture_width = 256;
const int texture_height = 256;
// 切り取った画像の大きさ
const int chip_width_num = texture_width / 5;
const int chip_height_num = texture_height / 5;
// 描画サイズ
// const int draw_size = 64;

class DRAWMAP {
public:

	void DrawMapChip(int map_size_width, int map_size_height, float texture_width, float texture_height, float mapchip_width, float mapchip_height, float draw_width, float draw_height, float draw_pos_x, float draw_pos_y, int texture, int** map);

	void TexturePrint(int drawpos_x, int drawpos_y, int mapcip_width, int mapchip_height, float chip_pos_x, float chip_pos_y, float width_num, float height_num, int texture);

	void InitMap();

	int map[world_size_width][world_size_height] = {};

private: 

};

#endif // !CHARCTER_H_
