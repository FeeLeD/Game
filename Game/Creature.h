#include "string"
using std::string;
#pragma once
class Creature
{
public:
	int healthPoints;
	int armorPoints;
	int hitPoints;
	int level;
	string name;

	void ReduceHP(int points) {
		healthPoints -= points;
	};
};

