#include "App.h"

App::App()
	:
	wnd(800, 600, "n3u2o^D3D")
{}

int App::Go()
{
	while (true)
	{
		// process all messages pending, but to not block for new messages
		if (const auto ecode = Window::ProcessMessages())
		{
			// if return optional has value, means we're quitting so return exit code
			return *ecode;
		}
		DoFrame();
	}
}

void App::DoFrame()
{
	const float t = timer.Peek();
	const float c = sin(t) / 2.0f + 0.5f;
	wnd.Gfx().ClearBuffer(c, c, 1.0f);
	float x_ndc, y_ndc;
	x_ndc = wnd.mouse.GetPosX() / 400.0f - 1.0f;
	y_ndc = -wnd.mouse.GetPosY() / 300.0f + 1.0f;
	wnd.Gfx().DrawTestTriangle(t, x_ndc, y_ndc);
	wnd.Gfx().EndFrame();
}