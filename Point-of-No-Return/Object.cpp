#include "Object.h"

/**
* @brief 描画関数
* @note ライブラリの関係もありとりあえずこれでいきます
*/

void Object::Draw() {
	dx.DrawEx(vec.x.value , vec.y.value , 0, size.width.value, size.height.value, degree.value, zoom.value, is_reverse.value, texture_name.value, uv.tu.value, uv.tv.value, texture_size.width.value, texture_size.height.value );
}
