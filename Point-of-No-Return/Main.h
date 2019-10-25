#ifndef MAIN_H
#define MAIN_H

#include "../Point-of-No-Return/Include/DirectX.h"

using DX::DirectX;

namespace Display
{
	const float DISPLAY_WIDTH = 1920;
	const float DISPLAY_HEIGHT = 1080;

	RECT DisplayRect
	{ 0,
	 0,
	 DISPLAY_WIDTH,
	 DISPLAY_HEIGHT
	};
}


LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp);

#endif