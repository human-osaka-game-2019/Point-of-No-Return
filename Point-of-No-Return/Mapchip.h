#ifndef MAPCHIP_H_
#define MAPCHIP_H_

#include<iostream>
#include<stdio.h>

// TODO: 引数などを修正したいので、doxygenコメントはリファクタリング時に記入する
class Mapchip {
public:
	// ワールドのサイズ
	static const int WORLD_SIZE_WIDTH = 480;
	static const int WORLD_SIZE_HEIGHT = 17;
	// 一つのチップのサイズ
	static const int CHIP_SIZE = 64;
	// テクスチャのサイズ
	static const int TEXTURE_WIDTH = 256;
	static const int TEXTURE_HEIGHT = 256;
	// テクスチャ一つに対するチップの番号
	static const int CHIP_WIDTH_NUM = TEXTURE_WIDTH / 4;
	static const int CHIP_HEIGHT_NUM = TEXTURE_HEIGHT / 4;

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
	int CalcMapNumber(int x, int y);

	//! マップの情報を保存するポインタ配列
	int* map_[WORLD_SIZE_HEIGHT];

private:
	//! マップの二重配列
	int map[WORLD_SIZE_HEIGHT][WORLD_SIZE_WIDTH] = {};

};

#endif // !MAPCHIP_H_
