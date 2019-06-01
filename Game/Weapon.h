#include "Items.h"
#include "cstdlib"
#include "ctime" 
#pragma once
enum WType { MACE, DAGGER, ROW, MAGIC };
class Weapon: public Items
{
private:
	string names[SIZE]{ "Наследие предков", "Мелодия стихий", "Шёпот смерти", "Священная ярость", "Последнее проклятие",
						 "Песнь победителя", "Северный ветер", "Острая шутка", "Момент истины", "Секрет титанов"};
	string GetName() {
		srand(unsigned int(time(0)));
		int randomNumber = rand();
		int position = rand() % 10;
		return names[position];
	};
	int GetDamage(IType it, WType wt) {
		double coficient;
		int result;
		switch (it)
		{
		case USUAL: coficient = 1;
			break;
		case RARE: coficient = 1.25;
			break;
		case LEGENDARY: coficient = 1.5;
			break;
		default:
			break;
		}
		
		switch (wt)
		{
		case MACE: result = 100 * coficient;
			break;
		case DAGGER: result = 80 * coficient;
			break;
		case ROW: result = 60 * coficient;
			break;
		case MAGIC: result = 50 * coficient;
			break;
		default:
			break;
		}
		return result;
	};
public:
	WType wtype;
	int damage;
	Weapon(IType it, WType wt);
	Weapon();
};

