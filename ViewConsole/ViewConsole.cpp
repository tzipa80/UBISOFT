// ViewConsole.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
//#include "AutoClosePtr.h"

//#pragma comment (lib,"Gdiplus.lib")
//#include <Windows.h>
//#include <GdiPlusEnums.h>
//#include <GdiPlusTypes.h>
//#include <GdiPlus.h>
#include "KCanvas.h"


//using namespace Gdiplus;
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
	/************************************************************************/
	/*                                                                      */
	/************************************************************************/
	
	
	Point vv;

	//const char szClassName[] = "MyApp"; // Имя оконного класса
	//WNDCLASSEX wc;
	//MSG msg;

	vv.X = 2;
	vv.Y = 2;

	ULONG_PTR m_gdiplusToken;
	// Initialize GDI+
	GdiplusStartupInput gdiplusStartupInput;
	GdiplusStartup(&m_gdiplusToken, &gdiplusStartupInput, NULL);

	KCanvas first;
	KRectangle rect;
	KCircle cir;
	first.KAddObject(&rect);
	first.KAddObject(&cir);
	while (true)
	{
		first.KFlush();

		Sleep(20);
	}




















	//HWND parent = GetConsoleWindow();
	

										   /*HWND desktop = GetDesktopWindow();

	HDC hdc = GetDC(application); //GetWindowDC(application); BeginPaint(application, &ps);


	HDC hdc2 = CreateDC(_T("DISPLAY"), NULL, NULL, NULL); //отрисовка происходмит на дисплее
	*/

	//char c;
	//Rect rc;

	//PAINTSTRUCT ps;


	/*
	//hInstance = GetModuleHandle(NULL);
	application = GetConsoleWindow(); //GetDesktopWindow();
	
	HDC hdc = GetDC(application);
	Rectangle(hdc, 120, 10, 220, 60);
	
	
	//KCanvas canvas(hdc);
	
	RECT f1;
	GetClientRect(application, &f1);// GetWindowRect(application, &f1);
	//int Height = GetSystemMetrics(SM_CYSCREEN);
	//int Width = GetSystemMetrics(SM_CXSCREEN);
	//cout << "Height: " << Height << endl;
	//cout << "Width: " << Width << endl;
	//RECT f2;
	//GetClientRect(application, &f2);

	int i = 0;
	Gdiplus::Graphics g(hdc);

	//Pen создоётся в стеке потому и удалять специально не нужно
	Pen      pen1(Gdiplus::Color(0, 0, 255), 2);
	Pen      pen2(Gdiplus::Color(0, 255, 0), 4);
	
	// Create a SolidBrush object в стеке.
	SolidBrush blackBrush(Color(10, 0, 255, 255));
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
		
		
		
		//g.Clear(Gdiplus::Color(0, 255, 255)); //Тормозит

		
		
		// Fill the rectangle.
		g.FillRectangle(&blackBrush, f1.left, f1.top, f1.right, f1.bottom); //f1.left, f1.bottom, f1.right, f1.top // 100, 100, 200, 200



		
		
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
		


		//FontFamily  fontFamily(L"Times New Roman");
		//Font        font(&fontFamily, 24, FontStyleRegular, UnitPixel);
		//SolidBrush  brush(Color(255, 0, 0, 255));

		//g.DrawString(TEXT("test of GDI+"), 13, &font, PointF(1600.0f, 300.0f), &brush); // dont work

		//g.DrawString(TEXT("test of GDI+"), 13, &font, PointF(500.0f, 300.0f), &brush); // work, but is in the primary screen



		//EndPaint(desktop, &ps);
		Sleep(3);
	}

	
	//c = getchar();
	//cout << c << endl;
	

	//ReleaseDC(application, hdc*/

	Gdiplus::GdiplusShutdown(m_gdiplusToken);
	
    return 0;
}

/*
HBITMAP CaptureWindow(void)
{

//Capture desktop into bitmap
HBITMAP hBitmap = NULL;
RECT rcDt;
HWND hDtWnd = ::GetForegroundWindow();


HDC hDtDC = GetDC(hDtWnd);


if(hDtDC && GetWindowRect(hDtWnd, &rcDt))
{
//Create mem DC & bitmap
int w = rcDt.right - rcDt.left;
int h = rcDt.bottom - rcDt.top;
HDC hMemDC = CreateCompatibleDC(hDtDC);
hBitmap = CreateCompatibleBitmap(hDtDC, w, h);


if(hMemDC && hBitmap)
{
//Select our bitmap
HGDIOBJ hOldBmp = SelectObject(hMemDC, hBitmap);

//Copy desktop to mem DC
BitBlt(hMemDC, 0,0, w, h, hDtDC, 0, 0, SRCCOPY);

//Select old bmp
SelectObject(hMemDC, hOldBmp);
}

//Release DCs
DeleteDC(hMemDC);
ReleaseDC(hDtWnd, hDtDC);
}

return hBitmap;
}
*/


/*
void SaveIt(HBITMAP hbmp, HDC hdc,const WCHAR *filename)
{
// using namespace Gdiplus;
// Initialize GDI+.
Gdiplus::GdiplusStartupInput gdiplusStartupInput;
ULONG_PTR gdiplusToken;
Gdiplus::GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);
CLSID   encoderClsid;
Gdiplus::Status stat;


// Get the CLSID of the PNG encoder.
GetEncoderClsid(L"image/png", &encoderClsid);

// Get width and height of source HBITMAP
BITMAP bm;
memset((void*)&bm, 0, sizeof(BITMAP));
GetObject(hbmp, sizeof(BITMAP), (void*)&bm);
int width = bm.bmWidth;
int height = bm.bmHeight;

// Create a GDI+ bitmap of the same dimensions, with alpha.
Gdiplus::Bitmap* copy = new Gdiplus::Bitmap(width, height, PixelFormat32bppRGB);
copy = new Gdiplus::Bitmap(hbmp, NULL);

//Gdiplus::Bitmap* copy = new Gdiplus::Bitmap(hbmp, NULL);

//Get an HDC for this new Bitmap
Gdiplus::Graphics* g =  Gdiplus::Graphics::FromImage(copy);
g->DrawImage(copy, 0, 0, 1280, 800);

HDC copyHdc = g->GetHDC();

HDC srcHdc = ::CreateCompatibleDC(hdc);
::SelectObject(srcHdc, hbmp);

//This loses all alpha:
// BOOL bbrv = ::BitBlt(copyHdc, 0, 0, width, height, srcHdc, 0,0, SRCCOPY);

//This retains some alpha (only where A == 0)
BLENDFUNCTION bf1;
bf1.BlendOp = AC_SRC_OVER;
bf1.BlendFlags = 0;
bf1.SourceConstantAlpha = 0xff;
bf1.AlphaFormat = AC_SRC_ALPHA;

BOOL abrv = ::AlphaBlend(copyHdc, 0, 0, width, height, srcHdc, 0, 0, width, height, bf1);


//

::DeleteDC(srcHdc);

g->ReleaseHDC(copyHdc);

stat = copy->Save(filename, &encoderClsid , NULL);

Gdiplus::GdiplusShutdown(gdiplusToken);

}
*/
