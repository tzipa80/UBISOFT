#include "KCanvas.h"
#define _USE_MATH_DEFINES
#include <math.h>




//void KObject::Drow() {
	//Get Old Position and Erase
	//GetPosition();

	//Get New Position and Drow it
	//GetNextPosition();
//}




//----------------------------------------------------------------
//KCanvas::KCanvas() : hWnd(NULL), hDC(NULL), g(NULL) {}


/*
KCanvas::~KCanvas()
{
	
}
void KCanvas::KInitGraphics() 
{
	//ULONG_PTR m_gdiplusToken;
	// Initialize GDI+
	//GdiplusStartupInput gdiplusStartupInput;
	GdiplusStartup(&m_gdiplusToken, &gdiplusStartupInput, NULL);
}

void KCanvas::KReleaseGraphics()
{
	//ReleaseDC(hWnd, hDC);
	//g->ReleaseHDC(hDC);

	Gdiplus::GdiplusShutdown(m_gdiplusToken);
}*/



void KCanvas::KCheckScale(Point p)
{
	if ((double)(p.X*ScaleFactorX) > (winRect.right * .9f)) {
		ScaleFactorX *= 0.5f; ScaleFactorY *= 0.5f;


	}
		
	    // ScaleFactorY -= 0.30f;
	   // ScaleFactorY *= 0.15;
	if ((double)(p.Y*ScaleFactorY) > (winRect.bottom * .9f)) {
		ScaleFactorY *= 0.5f; ScaleFactorX *= 0.5f;


	}
		
	   // ScaleFactorX -= 0.30f;
	  //  ScaleFactorX *= 0.15;

}

RESULT KCanvas::KAddObject(KObject *obj)
{
	if (!obj)
	{
		return RESULT_ERROR;
	}
	objects_list.push_back(obj);
	return RESULT_OK;

}

RESULT KCanvas::KFlush()
{
	Point cur;
	//static int i = 0;
	
	//g->Clear(Gdiplus::Color(0, 255, 255));
	
	//g->FillRectangle(backGraund, winRect.left, winRect.top, winRect.right, winRect.bottom);


	
	
	
	for (int i = 0; i < objects_list.size(); i++) {
		cur = objects_list[i]->GetPosition();
		//g->FillRectangle(backGraund, (int)(startLeft + cur.X*ScaleFactorX), (int)(startBottom - cur.Y*ScaleFactorY), 5, 5); //startLeft + cur.X, startBottom - cur.Y
		
		cur = objects_list[i]->GetNextPosition();
		//KCheckScale(cur);
		g->FillRectangle(objBrush, (int)(startLeft + cur.X*ScaleFactorX), (int)(startBottom - cur.Y*ScaleFactorY), 5, 5); //(int)((startBottom + cur.X)*ScaleFactorX), (int)((startLeft - cur.Y)*ScaleFactorY)
		//g->DrawRectangle(penAxis, (int)(startLeft + cur.X*ScaleFactorX), (int)(startBottom - cur.Y*ScaleFactorY), 5, 5);

	}

	//g->DrawLine(objBrush, 0, 0, winRect.right - i / 5, winRect.bottom);//  work, but is in the primary screen
	//g->DrawLine(pen2, 0, 0, winRect.right, winRect.bottom - i / 10);//  work, but is in the primary screen

	//i += (i / 5 < 500) ? 1 : -i;
	return RESULT_OK;
}

RESULT KCanvas::StartSemulation()
{
	return RESULT_OK;
}

Point KRectangle::GetNextPosition() 
{
	//pos.Y++;
	pos.X += 5; 
	//M_PI_2*
	pos.Y = 40*sin((M_PI/180)*((pos.X)%(int)(360.0/2.0))*2.0  ) + 100;
	return pos;
}


Point KCircle::GetNextPosition() 
{
	//pos.X++;
	//pos.Y++;

	pos.Y = objLib->getMPosition(pos.X++);
	return pos;
}