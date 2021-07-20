#pragma once
#include "Window.h"
#include "EngineTimer.h"

class App
{
public:
	App();
	int Go();//frame/msg loop
private:
	void DoFrame();//update
private:
	Window wnd;
	EngineTimer timer;
};

