#ifndef COLLISION
#define COLLISION

#include"Mapchip.h"
#include"Character.h"

enum Direction
{
	Stop,
	Up,
	Down,
	Right,
	Left,
	UpRight,
	UpLeft,
	DownRight,
	DownLeft
};

enum 
{ 
	Air,
	Road,

};

enum
{
	X,
	Y
};

enum HitPoint
{
	TopRight,
	TopLeft,
	BottomRight,
	BottomLeft,
	NoHit,

};



class Collision
{
private:

	int vec_x;
	int vec_y;

	int map_x;
	int map_y;

	// 配列の0番目にUPかDOWNが入り、配列の1番目にRIGHNTかLEFTが入る
	int save_char_move_direction[2] = {0};



	/**
	 * マップチップの二次元配列の中身を返す関数
	 * @param 対象のX座標
	 * @param 対象のY座標
	 * @param map情報のアドレス
	 * @return　マップチップの二次元配列の中身
	 */
	int CheckMapNumber(int x,int y, int** map);

public:
	
	/**
     * X軸の動きの方向を算出する関数
     * @param 対象のX座標
     * @param 対象の1フレーム前のX座標
     * @return Direction型の Right Left
     */
	Direction VerticalDirectionCheck(int x, int before_x);

	/**
	 * Y軸の動きの方向を算出する関数
	 * @param 対象のY座標
	 * @param 対象の1フレーム前のY座標
	 * @return Direction型の Up Down
	 */
	Direction HorizontalDirectionCheck(int y, int before_y);

	/**
     * ブロックとの当たり判定の関数
     * @param 対象のX座標
	 * @param 対象のX軸の描画サイズ
     * @param 対象のY座標
	 * @param 対象のY軸の描画サイズ
	 * @param 対象の1フレーム前のX座標
	 * @param 対象の1フレーム前のY座標
     * @param mapのアドレス
     */
	void ブロックとの(int x, int x_size, int y, int y_size, int before_x, int before_y, int** map);

	/**
	 * 各頂点を見て当たっているかどうかの確認関数
	 * @param 対象のX座標
	 * @param 対象のX軸の描画サイズ
	 * @param 対象のY座標
　　 * @param 対象のY軸の描画サイズ
	 * @param mapのアドレス
	 */
	bool HitPointCheck(int x, int x_size, int y, int y_size,int** map);

	/**
	 * どの方向に動いているかを判別する関数
	 * @param 対象のX座標
	 * @param 対象のX軸の描画サイズ
	 * @param 対象のY座標
　　 * @param 対象のY軸の描画サイズ
	 * @param mapのアドレス
	 */
	void DirectionCheck(int x, int x_size, int y, int y_size, int before_x, int before_y,int** map);

	/**
	 * 座標を修正する関数
	 * @param 対象のX座標
	 * @param 対象のX軸の描画サイズ
	 * @param 対象のY座標
　　 * @param 対象のY軸の描画サイズ
     * @param 対象の動いている方向
	 */
	void CoordinateCorrection(int x, int x_size, int y, int y_size,int direction);
	
	/**
	 * 右上の頂点がブロックにあたっているかどうかを判別する関数
	 * @param 対象のX座標
	 * @param 対象のX軸の描画サイズ
	 * @param 対象のY座標
	 * @return 当たっていたら true を返す
	 */
	bool TopRightHasHit(int x, int x_size, int y, int** map);

	/**
	 * 左上の頂点がブロックにあたっているかどうかを判別する関数
	 * @param 対象のX座標
	 * @param 対象のY座標
	 * @return 当たっていたら true を返す
	 */
	bool TopLeftHasHit(int x, int y, int** map);

	/**
	 * 右下の頂点がブロックにあたっているかどうかを判別する関数
	 * @param 対象のX座標
	 * @param 対象のX軸の描画サイズ
	 * @param 対象のY座標
　　 * @param 対象のY軸の描画サイズ
	 * @param mapのアドレス
	 * @return 当たっていたら true を返す
	 */
	bool BottomRightHasHit(int x, int x_size, int y, int y_size, int** map);


	/**
	 * 左下の頂点がブロックにあたっているかどうかを判別する関数
	 * @param 対象のX座標
	 * @param 対象のY座標
　　 * @param 対象のY軸の描画サイズ
	 * @param mapのアドレス
	 * @return 当たっていたら true を返す
	 */
	bool BottomLeftHasHit(int x, int y, int y_size,int** map);


	/**
	 * 斜めにめり込んだ時の当たり判定をどこの辺でとるのかを判別する関数
	 * @param 対象のX座標
	 * @param 対象のY座標
	 * @return どの当たり判定を使用するのかを返す
	 */
	int HitVectorJudge(int X, int Y, int move_deflection);
};



#endif
