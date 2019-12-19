#ifndef MAIN_H
#define MAIN_H

#include "Include/DirectX.h"
#include "Include/LogExporter.h"

using DX::DirectX;

namespace Display
{
	//! Displayの横幅
	const float WIDTH = 1920.f;

	//! Displayの縦幅
	const float HEIGHT = 1080.f;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp);

#endif
