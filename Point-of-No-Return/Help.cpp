#include "Help.h"
#include "Load.h"



void Help::Load()
{

}

void Help::Update()
{

}

void Help::Draw()
{

}

void Help::Release()
{

}

void Help::CreateLoadThread(HANDLE thread)
{
	thread = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)HelpThread, NULL, 0, NULL);
}

