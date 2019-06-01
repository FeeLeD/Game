#include "Creature.h"
#include "string"
#include "cstdlib"
#include "ctime"
#include "Location.h"
#include "MainCreature.h"

using std::string;

#pragma once
enum MType { ORC, GOLEMS, UNDEAD };
const int NAME_NUMBER = 7;
class Monster : public Creature
{
private:
	string names[NAME_NUMBER]{ "Морталис", "Шрум", "Барон Аргоний", "Магистр Фрогус", "Тёмный Уранус", "Сэр Мол", "Гром" };
	void GetName() {
		srand(unsigned int(time(0)));
		int randomNumber = rand();
		int position = rand() % NAME_NUMBER;
		name = names[position];
	};

	void SetStats(LType lt) {
		GetMonsterType();
		switch (mtype)
		{
		case MType::ORC:
			OrcStats(mainHero);
			break;
		case MType::GOLEMS:
			GolemsStats(mainHero);
			break;
		case MType::UNDEAD:
			UndeadStats(mainHero);
			break;
		default:
			break;
		}
	};

	void OrcStats(MainCreature mc) {
		int maxHP, maxHtP,maxAP, maxLVL, maxAttRange, maxDefRange;

		if (mc.fightsNumber == 0) {
			maxHP = 300;
			maxHtP = 50;
			maxAP = 0;
			maxLVL = 1;
			maxAttRange = 10;
			maxDefRange = 10;
		}
		else if (mc.fightsNumber == 1){
			maxHP = 350;
			maxHtP = 70;
			maxAP = 0;
			maxLVL = 3;
			maxAttRange = 15;
			maxDefRange = 10;
		}
		else {
			maxHP = 600;
			maxHtP = 80;
			maxAP = 0;
			maxLVL = 5;
			maxAttRange = 15;
			maxDefRange = 10;
		};
		healthPoints = maxHP;
		hitPoints = maxHtP;
		armorPoints = maxAP;
		level = maxLVL;
		attackRange = maxAttRange;
		defenceRange = maxDefRange;
	};

	void GolemsStats(MainCreature mc) {
		//В разработке...
	};

	void UndeadStats(MainCreature mc) {
		//В разработке...
	};

	void GetMonsterType() {
		switch (location)
		{
		case LType::DEEPFOREST: mtype = MType::ORC;
			break;
		case LType::GIANTDRAWINGS: mtype = MType::GOLEMS;
			break;
		case LType::CURVEDGROUND: mtype = MType::UNDEAD;
			break;
		default:
			break;
		}
	};

public:
	Monster(LType lt, MainCreature mc);
	MainCreature mainHero;
	LType location;
	MType mtype;
	int attackRange;
	int defenceRange;
};

