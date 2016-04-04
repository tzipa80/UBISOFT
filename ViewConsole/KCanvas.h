#include <Windows.h>
//#include <iostream>
#include <vector>
#include <GdiPlus.h>
#include <GdiPlusEnums.h>
#include <GdiPlusTypes.h>
#pragma comment (lib,"Gdiplus.lib")


#include "MovementLib.h"

#pragma comment(lib, "MovementLib.lib")


#pragma once

//#define 

using namespace Gdiplus;
using namespace std;


enum RESULT {
		RESULT_OK,
		RESULT_ERROR
};




class KObject
{
public:
	enum SHAPE { RECTANGLE, CIRCLE };
	KObject() {};
	virtual ~KObject() {};

	virtual Point GetPosition() = 0;
	virtual Point GetNextPosition() = 0;

	//void Drow();

	SHAPE eShape;
private:

};

class KRectangle : public KObject
{
private:
	Point pos;
public:
	KRectangle():pos(0, 0) { this->eShape = KObject::RECTANGLE; };
	~KRectangle() {};
	Point GetPosition() { return pos; };
	Point GetNextPosition();
};

class KCircle : public KObject
{
private:
	Point pos;
	IMovement *objLib;
public:
	KCircle() :pos(0, 0) {
		this->eShape = KObject::CIRCLE; objLib = GetMovmentLib();
	};
	~KCircle() { objLib->Release(); };
	Point GetPosition() { return pos; };
	Point GetNextPosition();
};



class KCanvas
{
	//ULONG_PTR m_gdiplusToken;
	// Initialize GDI+
	//GdiplusStartupInput gdiplusStartupInput;
	HWND hWnd;
	HDC hDC;
	Gdiplus::Graphics *g;

	vector<KObject *> objects_list;

	Pen      *penAxis;
	//Pen      *pen2;

	// Create a SolidBrush object в стеке.
	SolidBrush *backGraund;

	SolidBrush *objBrush;

private:
	REAL ScaleFactorX;
	REAL ScaleFactorY;
	RECT winRect;
	int startBottom;
	int startLeft;
	void KCheckScale(Point p);
	//void KInitGraphics();
	//void KReleaseGraphics();
public:
	KCanvas(): //g(NULL),
		ScaleFactorY(1.0f),
		ScaleFactorX(1.0f)
	{
		//KInitGraphics();
		hWnd = GetConsoleWindow();
		hDC = GetDC(hWnd); //GetDC(hWnd);
		g = Gdiplus::Graphics::FromHDC(hDC); //new Gdiplus::Graphics(hDC);
		GetClientRect(hWnd, &winRect);
		startLeft = winRect.left + 10;
		startBottom = winRect.bottom - 10;

		   //pen2 = new Pen(Gdiplus::Color(0, 255, 0), 4);

		// Create a SolidBrush 
		   backGraund = new SolidBrush(Color(255, 0, 255, 255));
		   g->FillRectangle(backGraund, winRect.left, winRect.top, winRect.right, winRect.bottom);

		   objBrush = new SolidBrush(Color(255, 255, 0, 0));


		   penAxis = new Pen(Gdiplus::Color(0, 255, 0), 3);
		   g->DrawLine(penAxis, startLeft, winRect.bottom, startLeft, winRect.top);
		   g->DrawLine(penAxis, winRect.left, startBottom, winRect.right, startBottom);


	};
	//KCanvas(HDC hDCUser) : //g(NULL),
	//	ScaleFactorY(1.0f),
	//	ScaleFactorX(1.0f)
	//{
		//hWnd = GetConsoleWindow();
	//	hDC = ::CreateCompatibleDC(hDCUser); //GetDC(hWnd);
	//	g = Gdiplus::Graphics::FromHDC(hDCUser); //new Gdiplus::Graphics(hDC);
	//	GetClientRect(WindowFromDC(hDC), &winRect);
	//};
	~KCanvas() {
		//g->ReleaseHDC(hDC);
		//KReleaseGraphics();
	};

	REAL GetScaleFactorX()const { return ScaleFactorX; }
	REAL GetScaleFactorY()const { return ScaleFactorY; }
	
	//void KFlush();

	//RESULT AddObject(KObject *);

	RESULT KAddObject(KObject *);
	RESULT StartSemulation();

	RESULT KFlush();
};

