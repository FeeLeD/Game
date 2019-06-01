#include "stdafx.h"
#include "Armor.h"
#include "Items.h"

Armor::Armor(IType it, AType at)
{
	itype = it;
	atype = at;
	name = GetName();
	points = GetPoints(it, at);
}

Armor::Armor()
{
	name = "Гражданская одежда";
	points = 0;
}
