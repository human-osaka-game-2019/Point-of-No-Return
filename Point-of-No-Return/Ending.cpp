#include "Ending.h"
#include "Load.h"


void Ending::Load() 
{

}

void Ending::Update()
{

}

void Ending::Draw()
{

}

void Ending::Release()
{

}

void Ending::CreateLoadThread(HANDLE thread)
{
	thread = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)EndingThread, NULL, 0, NULL);
}


