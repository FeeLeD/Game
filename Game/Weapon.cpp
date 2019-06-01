#include "stdafx.h"
#include "Weapon.h"
#include "Weapon.h"
#include "Items.h"
#include "string"
#include "cstdlib"
#include "ctime" 


using std::string;

Weapon::Weapon(IType it, WType wt)
{
	itype = it;
	wtype = wt;
	name = GetName();
	damage = GetDamage(it, wt);
}

Weapon::Weapon()
{
	name = "Кулаки";
	damage = 15;
}
