#include "stdafx.h"
#include "Location.h"
#include "Logic.h"

Logic::Logic()
{
	location.ltype = LType::DEEPFOREST;
	actionsNumbers = GetActNumber();
}