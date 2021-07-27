#include "App.h"
#include <sstream>
#include <iomanip>

App::App()
	:
	wnd(640, 480, "n3u2o win32 C++ framework")
{}

int App::Go()
{
	while (true)
	{
		if (const auto ecode = Window::ProcessMessages())
		{
			return *ecode;
		}
		DoFrame();
	}
}

void App::DoFrame()//game logic
{
	const float t = timer.Peek();
/*	std::ostringstream oss;
	oss << "Time elapsed: " << std::setprecision(1) << std::fixed << t << "s";
	wnd.SetTitle(oss.str());*/
	const float c = sin(t) / 2.0f + 5.0f;
	wnd.Gfx().ClearBuffer(c, c, 1.0f);
	wnd.Gfx().DrawTestShape();
	wnd.Gfx().EndFrame();
}