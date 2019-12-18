﻿#ifndef FRAMEBASE_H
#define FRAMEBASE_H

#include "../UI.h"

/**
 * @brief FrameBaseクラス
 */
class FrameBase
{
public:

	DX::DirectX& dx = DX::DirectX::GetInstance();

	virtual void Initialize() = 0;
	virtual void Draw() = 0;
	virtual ~FrameBase() {};

protected:

	Position position =
	{
		CoordinateX(0),
		CoordinateY(0)
	};

	Size size =
	{
		Width(0),
		Height(0)
	};

	TextureUV uv =
	{
		TextureU(0),
		TextureV(0)
	};

	TextureSize texture_size =
	{
		Width(0),
		Height(0)
	};

	TextureName texture_name = TextureName("Action");

	Degree degree = Degree(0);
	Zoom zoom = Zoom(0);
	IsReverse is_reverse = IsReverse(false);

};

#endif
