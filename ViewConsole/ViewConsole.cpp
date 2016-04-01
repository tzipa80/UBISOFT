// ViewConsole.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
//#include "AutoClosePtr.h"



#pragma comment (lib,"Gdiplus.lib")
#include <Windows.h>
#include <GdiPlusEnums.h>
#include <GdiPlusTypes.h>
#include <GdiPlus.h>


using namespace Gdiplus;
using namespace std;

//HINSTANCE hInstance;

//static HWND  hConWnd;

//HWND GetConsoleWndHandle(void);
//HWND BCX_Bitmap(char*, HWND = 0, int = 0, int = 0, int = 0, int = 0, int = 0, int = 0, int = 0, int = 0);
// Объявление оконной процедуры

//HINSTANCE  hInstance;
HWND application;


int main(int argc, char **argv)
{
	//const char szClassName[] = "MyApp"; // Имя оконного класса
	//WNDCLASSEX wc;
	//MSG msg;

	ULONG_PTR m_gdiplusToken;
	// Initialize GDI+
	GdiplusStartupInput gdiplusStartupInput;
	GdiplusStartup(&m_gdiplusToken, &gdiplusStartupInput, NULL);

	//HWND parent = GetConsoleWindow();
	

										   /*HWND desktop = GetDesktopWindow();

	HDC hdc = GetDC(application); //GetWindowDC(application); BeginPaint(application, &ps);


	HDC hdc2 = CreateDC(_T("DISPLAY"), NULL, NULL, NULL); //отрисовка происходмит на дисплее
	*/

	//char c;
	//Rect rc;

	//PAINTSTRUCT ps;

	//hInstance = GetModuleHandle(NULL);
	application = GetConsoleWindow(); //GetDesktopWindow();
	
	HDC hdc = GetDC(application);
	RECT f1;
	
	GetClientRect(application, &f1);// GetWindowRect(application, &f1);
	//int Height = GetSystemMetrics(SM_CYSCREEN);
	//int Width = GetSystemMetrics(SM_CXSCREEN);

	//RECT f2;
	//GetClientRect(desktop, &f2);

	int i = 0;
	Gdiplus::Graphics g(hdc);

	//Pen создоётся в стеке потому и удалять специально не нужно
	Pen      pen1(Gdiplus::Color(0, 0, 255), 2);
	Pen      pen2(Gdiplus::Color(0, 255, 0), 4);
	
	// Create a SolidBrush object в стеке.
	SolidBrush blackBrush(Color(100, 0, 255, 255));
	while (true)
	{

		//HPEN newpen;
		//LPPOINT point = NULL;
		//newpen = CreatePen(PS_COSMETIC, 20, RGB(255, 0, 0));
		//SelectObject(hdc, newpen);
		//MoveToEx(hdc, 1500, 500, point);
		//LineTo(hdc, 1600, 550);
		//this block works for draw line in second monitor

		//TextOut(hdc, 1500, 300, TEXT("Text of text out"), 17); // this works too
		
		
		
		//g.Clear(Gdiplus::Color(0, 255, 255));

		
		
		// Fill the rectangle.
		g.FillRectangle(&blackBrush, f1.left+100, f1.top+100, f1.right, f1.bottom); //f1.left, f1.bottom, f1.right, f1.top // 100, 100, 200, 200



		
		
		g.DrawLine(&pen1, 0, 0, f1.right-i/5, f1.bottom);//  work, but is in the primary screen
		g.DrawLine(&pen2, 0, 0, f1.right, f1.bottom-i/10);//  work, but is in the primary screen

		i += (i/5 < 500) ? 1 : -i;



		

		//Походу толко в MFC
		/*PAINTSTRUCT ps;
		HDC            hdcA;
		hdcA = ::BeginPaint(application, &ps);

		::Rectangle(
			hdcA,
			100,
			100,
			200,
			200
			);

		::EndPaint(application, &ps);*/



		/*
		Gdiplus::Graphics g2(hdc2);

		Pen      pen11(Gdiplus::Color(0, 255, 255), 2);
		Pen      pen22(Gdiplus::Color(255, 255, 0), 2);

		//g.DrawLine(&pen, 1500, 0, 1700, 600);// dont work

		g2.DrawLine(&pen11, 0, 0, f2.right - 35, f2.bottom);//  work, but is in the primary screen
		g2.DrawLine(&pen22, 0, 0, f2.right, f2.bottom);//  work, but is in the primary screen
		*/


		//FontFamily  fontFamily(L"Times New Roman");
		//Font        font(&fontFamily, 24, FontStyleRegular, UnitPixel);
		//SolidBrush  brush(Color(255, 0, 0, 255));

		//g.DrawString(TEXT("test of GDI+"), 13, &font, PointF(1600.0f, 300.0f), &brush); // dont work

		//g.DrawString(TEXT("test of GDI+"), 13, &font, PointF(500.0f, 300.0f), &brush); // work, but is in the primary screen



		//EndPaint(desktop, &ps);
		Sleep(50);
	}

	
	//c = getchar();
	//cout << c << endl;
	

	ReleaseDC(application, hdc);

	Gdiplus::GdiplusShutdown(m_gdiplusToken);
	
    return 0;
}



