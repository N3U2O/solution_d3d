#pragma once
#include "Window.h"

class App
{
public:
	App();
	int Go();//frame/msg loop
private:
	void DoFrame();
private:
	Window wnd;
};

