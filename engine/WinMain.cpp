/*  ===============================================================
	$File: WinMain.cpp$
	$Date: 19/07/2021$
	$Revision: 0.1$
	$Creator: n3u2o $
	$Notice: (C) Copyright 2021 by n3u2o, ~, All Rights Reserved. $
	===============================================================  */

#ifdef UNICODE
#undef UNICODE
#endif

#define CONFIGURE_NOSHIT

#include "ConfigureWindows.h"
#include "WindowsMessageMap.h"

#include <sstream>

static const auto pTitle = "n3u2o win32";

LRESULT CALLBACK WndProc(
	HWND   hWnd,
	UINT   msg,
	WPARAM wParam,
	LPARAM lParam)
{
	static bool windowTextChanged = false;
	static WindowsMessageMap mm;
	OutputDebugString(mm(msg, lParam, wParam).c_str());
	switch (msg)
	{
	case WM_CLOSE:
		PostQuitMessage(69);
		break;
	case WM_KEYDOWN:
		if (wParam == 'F')
		{
			SetWindowText(hWnd, "cica");
			windowTextChanged = true;
		}
		break;
	case WM_KEYUP:
		if (wParam == 'F')
		{
			SetWindowText(hWnd, pTitle);
		}
		break;
	case WM_LBUTTONDOWN:
	{
		const POINTS pt = MAKEPOINTS(lParam);
		std::ostringstream oss;
		oss << "(" << pt.x << "," << pt.y << ")";
		SetWindowText(hWnd, oss.str().c_str());
	}
		break;
	}
	return DefWindowProc(hWnd, msg, wParam, lParam);
}

int CALLBACK WinMain(
	_In_		HINSTANCE	hInstance,
	_In_opt_	HINSTANCE	hPrevInstance,
	_In_		LPSTR		lpCmdLine,
	_In_		int			nShowCmd
)
{
	const auto pClassName = "N3DClass";
	WNDCLASSEX wc = { 0 };
	wc.cbSize = sizeof(wc);
	wc.style = CS_OWNDC;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = nullptr;
	wc.hIconSm = nullptr;
	wc.hCursor = nullptr;
	wc.hbrBackground = nullptr;
	wc.lpszMenuName = nullptr;
	wc.lpszClassName = pClassName;
	RegisterClassEx(&wc);

	HWND hWnd = CreateWindowEx(
		0, pClassName, pTitle,
		WS_MINIMIZEBOX | WS_SYSMENU | WS_CAPTION,
		200, 200, 640, 480,
		nullptr, nullptr, hInstance, nullptr
	);
	ShowWindow(hWnd, SW_SHOW);

	MSG msg;
	BOOL gmresult;
	while ((gmresult = GetMessage(&msg, nullptr, 0, 0)) > 0)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return (gmresult == -1) ? -1 : (int)(msg.wParam);
}

