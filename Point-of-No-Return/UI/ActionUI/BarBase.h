#ifndef BARBASE_H
#define BARBASE_H

#include "../UI.h"
#include "../../Character.h"

/**
 * @brief BerBaseクラス
 */
class BarBase
{
public:

	DX::DirectX& dx = DX::DirectX::GetInstance();

	virtual void Initialize() {};
	virtual void Draw() {};
	BarBase() {};
	virtual ~BarBase() {};

	inline Size GetDrawSize()
	{
		return size;
	};

protected:

	Vec2 position =
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

	const float MAX_WIDTH = 576;
	const float HEIGHT = 48;

};




#endif
