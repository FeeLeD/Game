#include "Items.h"
#include "cstdlib"
#include "ctime" 
#pragma once
enum AType { CORSLET, CHAIN, LIGHT, CLOTHES };
class Armor: public Items
{
private:
	string names[SIZE]{ "Знаменитый следопыт", "Великий герой", "Титан", "Мистик", "Прославленный герой",
						"Верховный повелитель", "Смертоносная молния", "Неразрушимый монолит", "Блуждающий странник", "Небесный волшебник" };
	string GetName() {
		srand(unsigned int(time(0)));
		int randomNumber = rand();
		int position = rand() % 10;
		return names[position];
	};
	int GetPoints(IType it, AType at) {
		double coficient;
		int result;
		switch (it)
		{
		case USUAL: coficient = 1;
			break;
		case RARE: coficient = 1.5;
			break;
		case LEGENDARY: coficient = 2;
			break;
		default:
			break;
		}

		switch (at)
		{
		case CORSLET: result = 50 * coficient;
			break;
		case CHAIN: result = 40 * coficient;
			break;
		case LIGHT: result = 30 * coficient;
			break;
		case CLOTHES: result = 10 * coficient;
			break;
		default:
			break;
		}
		return result;
	};
public:
	AType atype;
	int points;
	Armor(IType it, AType at);
	Armor();
};

