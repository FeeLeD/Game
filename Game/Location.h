#include "string"
using std::string;
#pragma once
enum LType { DEEPFOREST, GIANTDRAWINGS, CURVEDGROUND };
class Location
{
private:
	void GetName() {
		switch (ltype)
		{
		case DEEPFOREST: name = "Вековые леса";
			break;
		case GIANTDRAWINGS: name = "Чертоги гигантов";
			break;
		case CURVEDGROUND: name = "Проклятые земли";
			break;
		default:
			break;
		}
	};
public:
	LType ltype;
	string name;
	Location();
};

