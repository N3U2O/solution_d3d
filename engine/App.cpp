#include "App.h"

App::App()
	:
	wnd(640, 480, "n3u2o win32 C++ framework")
{}

int App::Go()
{
	MSG msg;
	BOOL mresult;
	while ((mresult = GetMessage(&msg, nullptr, 0, 0)) > 0)
	{
		TranslateMessage(&msg);//post aux. WM_CHAR msgs from key...msgs
		DispatchMessage(&msg);
		DoFrame();
	}

	if (mresult == -1)
	{
		throw EW_LAST_EXCEPT();
	}

	return msg.wParam;
}

void App::DoFrame()
{
	//game logic
}