#include "Load.h"

//void Thread::Load()
//{
//	HANDLE th;
//	//スレッドを作成
//	th = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)Thread::Thread1, NULL, 0, NULL);
//
//	if (th == NULL)
//	{
//		return;
//	}
//
//	DWORD Prev = timeGetTime();
//	DWORD Curr;
//
//	DWORD result;
//
//	timeBeginPeriod(1);
//
//	int fc_ui_tv = 0;
//	float tv_ = 0.0f;
//	
//	//Thread関数が処理している間のループ
//	while (true)
//	{
//		Curr = timeGetTime();
//		if (Curr - Prev >= 1000 / 60) {
//
//			
//
//
//			
//			//スレッドが終わったかチェック
//			GetExitCodeThread(th, &result);
//			if (STILL_ACTIVE != result)
//			{
//				//closehandleで閉じる。
//				CloseHandle(th);
//				//ループを抜ける。
//				break;
//			}
//
//
//			
//			Prev = Curr;
//
//		}
//		Sleep(1);
//	}
//	timeEndPeriod(1);
//}
//
////終わったかどうか返す関数
//
//
//
////スレッド関数
//DWORD WINAPI Thread::Thread1(HWND hWnd, LPVOID* data)
//{
//	//Load中に裏でしたい処理
//	scenebase->Load();
//
//	ExitThread(0);
//}
