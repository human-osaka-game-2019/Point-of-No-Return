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
	// 一つのチップのサイズ
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
	void DrawMapchip(float draw_start_pos_x, float draw_start_pos_y, std::string texturename, int** map);

	/**
	 * @brief  
	 * @param  
	 * @param  
	 * @param  
	 * @details 
	 */
	void TexturePrint(float drawpos_x, float drawpos_y, float tu, float tv, std::string texturename);

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
