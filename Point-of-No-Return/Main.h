#ifndef MAIN_H
#define MAIN_H

#include "Include/DirectX.h"
#include "Include/LogExporter.h"

using DX::DirectX;



namespace Display
{
	const float DISPLAY_WIDTH = 1920;
	const float DISPLAY_HEIGHT = 1080;

}


LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp);

#endif
