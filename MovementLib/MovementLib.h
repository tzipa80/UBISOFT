#pragma once
#ifdef MOVEMENTLIB_EXPORTS
#define MOVMENT_API __declspec(dllexport) 
#else
#define MOVMENT_API __declspec(dllimport)
#endif

struct IMovement
{
	virtual int getMPosition(int xPos) = 0;
	virtual void Release() = 0;


};


extern "C" MOVMENT_API IMovement* APIENTRY GetMovmentLib();