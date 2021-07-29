#include "App.h"

App::App()
	:
	wnd( 1024,576,"n3u2o^D3D" )
{}

int App::Go()
{
	while( true )
	{
		// process all messages pending, but to not block for new messages
		if( const auto ecode = Window::ProcessMessages() )
		{
			// if return optional has value, means we're quitting so return exit code
			return *ecode;
		}
		DoFrame();
	}
}

void App::DoFrame()
{
	const float c = sin( timer.Peek() ) / 2.0f + 0.5f;
	wnd.Gfx().ClearBuffer( c,c,1.0f );
	wnd.Gfx().DrawTestTriangle();
	wnd.Gfx().EndFrame();
}