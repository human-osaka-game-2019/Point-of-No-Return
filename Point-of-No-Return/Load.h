#ifndef LOAD_H_
#define LOAD_H_

#include <windows.h>

DWORD WINAPI TitleThread(HWND hWnd, LPVOID* data);

DWORD WINAPI HelpThread(HWND hWnd, LPVOID* data);

DWORD WINAPI GameThread(HWND hWnd, LPVOID* data);

DWORD WINAPI EndingThread(HWND hWnd, LPVOID* data);


#endif

