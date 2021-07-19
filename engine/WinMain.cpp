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
	//#include "WindowsMessageMap.h"
#include "Window.h"

int CALLBACK WinMain(
	_In_		HINSTANCE	hInstance,
	_In_opt_	HINSTANCE	hPrevInstance,
	_In_		LPSTR		lpCmdLine,
	_In_		int			nShowCmd
)
{
	try
	{
		Window wnd(640, 480, "n3u2o win32 C++ framework");

		MSG msg;
		BOOL gmresult;
		while ((gmresult = GetMessage(&msg, nullptr, 0, 0)) > 0)
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		if (gmresult == -1)
		{
			return -1;
		}

		return (int)(msg.wParam);
	}
	catch (const EngineException& e)
	{
		MessageBox(nullptr, e.what(), e.GetType(), MB_OK | MB_ICONEXCLAMATION);
	}
	catch (const std::exception& e)
	{
		MessageBox(nullptr, e.what(), "Standard Exception", MB_OK | MB_ICONEXCLAMATION);
	}
	catch (...)
	{
		MessageBox(nullptr, "No details available", "Unknown Exception", MB_OK | MB_ICONEXCLAMATION);
	}
	return -1;
}

