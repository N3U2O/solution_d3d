/*  ===============================================================
    $File: WinMain.cpp$
    $Date: 19/07/2021$
    $Revision: 0.1$
    $Creator: n3u2o $
    $Notice: (C) Copyright 2021 by n3u2o, ~, All Rights Reserved. $
    ===============================================================  */

//#include "WindowsConf.h"
#undef UNICODE
#include <Windows.h>

int CALLBACK WinMain(
    HINSTANCE   hInstance,
    HINSTANCE   hPrevInstance,
    LPSTR       lpCmdLine,
    int         nCmdShow )
{
    const auto pClassName = "N3DClass";
    WNDCLASSEX wc = {0};
    wc.cbSize = sizeof( wc );
    wc.style = CS_OWNDC;
    wc.lpfnWndProc = DefWindowProc;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = hInstance;
    wc.hIcon = nullptr;
    wc.hIconSm = nullptr;
    wc.hCursor = nullptr;
    wc.hbrBackground = nullptr;
    wc.lpszMenuName = nullptr;
    wc.lpszClassName = pClassName;
    RegisterClassEx( &wc );

    HWND hWnd = CreateWindowEx(
        0, pClassName,
        "n3u2o Win32",
        WS_MINIMIZEBOX | WS_SYSMENU | WS_CAPTION,
        200, 200, 400, 300,
        nullptr, nullptr, hInstance, nullptr
        );
    ShowWindow(hWnd, SW_SHOW);
    while (true);
    return 0;
}