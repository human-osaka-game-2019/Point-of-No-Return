#include "Title.h"
#include "Load.h"

void Title::Load()
{



}

void Title::Update()
{



}

void Title::Draw()
{



}

void Title::Release()
{



}

void Title::CreateLoadThread(HANDLE thread)
{
	//スレッドを作成
	thread = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)TitleThread, NULL, 0, NULL);

}

