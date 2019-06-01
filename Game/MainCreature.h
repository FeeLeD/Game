#include "Creature.h"
#include "Items.h"
#include "Decoration.h"
#include "Weapon.h"
#include "Armor.h"
#pragma once
int const MAX_SIZE = 3;
class MainCreature: public Creature
{
private:
	void SetInitital() {
		healthPoints = 500;
		armorPoints = 0;
		hitPoints = 50;
		level = 0;
		fightsNumber = 0;
		experience = 0;
	};
public:
	int fightsNumber;
	double energy;
	int experience;
	Decoration backpack[MAX_SIZE];
	Weapon weapon;
	Armor armor;
	MainCreature(string n);
	MainCreature();

	void CheckLevel() {
		if (experience >= 100) {
			experience = 0;
			level++;

			healthPoints += 50;
			hitPoints += 20;
		}		
	};
};

