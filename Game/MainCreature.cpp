#include "stdafx.h"
#include "MainCreature.h"
#include "Creature.h"
#include "string"

using std::string;

MainCreature::MainCreature(string n)
{
	name = n;
	SetInitital();
}

MainCreature::MainCreature()
{
	name = "no name";
	SetInitital();
}

