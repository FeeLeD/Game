#include "stdafx.h"
#include "Monster.h"
#include "Creature.h"
#include "string"
#include "cstdlib"
#include "ctime"
#include "Location.h"
#include "MainCreature.h"

using std::string;

Monster::Monster(LType lt, MainCreature mc)
{
	location = lt;
	mainHero = mc;
	GetName();
	SetStats(location);
}
