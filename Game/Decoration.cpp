#include "stdafx.h"
#include "Decoration.h"
#include "Items.h"


Decoration::Decoration(IType it, DType dt)
{
	itype = it;
	dtype = dt;
	buffNumber = WhatToBuff();
	coficient = GetCoficient(it);
	name = GetName(dt, buffNumber, coficient);
}
Decoration::Decoration()
{
	name = "Пусто";
	coficient = 1;
	buffNumber = 0;
	on = true;
}
