﻿#ifndef MAPCHIP_H_
#define MAPCHIP_H_

#include<iostream>

#include "Character.h"
#include "Main.h"

// TODO: 引数などを修正したいので、doxygenコメントはリファクタリング時に記入する
class Mapchip {
public:
	//! ワールドの横のブロック数
	static const int WORLD_HORIZONTAL_NUM = 480;

	//! ワールドの縦のブロック数
	static const int WORLD_VERTICAL_NUM = 17;

	//! 一つのチップのサイズ
	static const int CHIP_SIZE = 64;

	//! テクスチャの横幅
	static const int TEXTURE_WIDTH = 256;

	//! テクスチャの縦幅
	static const int TEXTURE_HEIGHT = 256;

	//! テクスチャ一つに対するチップの横の番号
	static const int CHIP_WIDTH_NUM = TEXTURE_WIDTH / 4;

	//! テクスチャ一つに対するチップの縦の番号
	static const int CHIP_HEIGHT_NUM = TEXTURE_HEIGHT / 4;

	Mapchip()
	{
		InitMap();
	}

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
	 * @details	Mapchipのコンストラクタで呼ぶ
	 */
	void InitMap();

	/**
	 * @brief		指定した座標の行と列の詰まったMatrixを返す関数
	 * @param	position	割り出したいX座標の位置
	 * @param	offset		割り出したいY座標の位置
	 * @return	Matrix	指定した座標の現在の行と列の詰まったMatrix
	 */
	static Matrix CalcMapMatrix(const Position& position,const Position& offset);

	/**
	 * @brief		指定した行と列の座標の詰まったMatrixを返す関数
	 * @param	matrix		割り出したいX座標の位置
	 * @param	offset		割り出したいY座標の位置
	 * @return	Position	
	 */
	static Position CalcMapPosition(const Matrix& matrix,const Position& offset);

	//! マップの情報を保存するポインタ配列
	int* map_[WORLD_VERTICAL_NUM];

private:

	// テクスチャの横のブロック数
	const int HORIZONTAL_NUM = TEXTURE_WIDTH / CHIP_WIDTH_NUM;

	// テクスチャの縦のブロック数
	const int VERTICAL_NUM = TEXTURE_HEIGHT / CHIP_HEIGHT_NUM;

	//! 描画する最小値
	const float DRAW_MIN = -CHIP_SIZE;

	//! 描画する最大値
	const float DRAW_MAX = Display::WIDTH + CHIP_SIZE;

	//! マップの二重配列
	int map[WORLD_VERTICAL_NUM][WORLD_HORIZONTAL_NUM] = {};

};

#endif // !MAPCHIP_H_
