#ifndef MAPCHIP_H_
#define MAPCHIP_H_

#include<iostream>
#include<stdio.h>

namespace
{
	// ワールドのサイズ
	const int world_size_width = 480;
	const int world_size_height = 17;
	// 一つのチップのサイズ
	const int chip_size = 64;
	// テクスチャのサイズ
	const int texture_width = 256;
	const int texture_height = 256;
	// テクスチャ一つに対するチップの番号
	const int chip_width_num = texture_width / 4;
	const int chip_height_num = texture_height / 4;
}

// TODO: 引数などを修正したいので、doxygenコメントはリファクタリング時に記入する
class Mapchip {
public:
	/**
	 * @brief  マップチップを描画する関数
	 * @param  
	 * @param  
	 * @param  
	 * @details 
	 */
	void DrawMapchip(int map_size_width, int map_size_height, float texture_width, float texture_height, float mapchip_width, float mapchip_height, float draw_width, float draw_height, float draw_pos_x, float draw_pos_y, std::string texturename, int** map);

	/**
	 * @brief  
	 * @param  
	 * @param  
	 * @param  
	 * @details 
	 */
	void TexturePrint(int drawpos_x, int drawpos_y, int mapcip_width, int mapchip_height, float chip_pos_x, float chip_pos_y, float width_num, float height_num, std::string texturename);

	/**
	 * @brief	マップの初期化
	 * @details	Gameのコンストラクタで呼ぶ
	 */
	void InitMap();

	/**
	 * @brief		マップの位置を割り出す関数
	 * @param	x	割り出したいX座標の位置
	 * @param	y	割り出したいY座標の位置
	 * @param	map	マップのポインタの配列
	 * @return		
	 */
	int CheckMapNumber(int x, int y, int** map);

	//! マップの情報を保存するポインタ配列
	int* map_[world_size_height];

private:
	//! マップの二重配列
	int map[world_size_height][world_size_width] = {};

};

#endif // !MAPCHIP_H_
