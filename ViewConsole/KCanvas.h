#include <Windows.h>

#pragma once
class KCanvas
{
	HWND hWnd;
	HDC hDC;

public:
	KCanvas();
	virtual ~KCanvas();
};

