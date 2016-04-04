// MovementLib.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "MovementLib.h"

class MovementImp : public IMovement
{
	int getMPosition(int xPos);
	void Release();
};

int MovementImp::getMPosition(int xPos)
{
	return xPos;
}


void MovementImp::Release()
{



}


MOVMENT_API IMovement* APIENTRY GetMovmentLib()
{
	IMovement *p = new MovementImp;


	return p;
}
