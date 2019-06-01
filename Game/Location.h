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
		case DEEPFOREST: name = "������� ����";
			break;
		case GIANTDRAWINGS: name = "������� ��������";
			break;
		case CURVEDGROUND: name = "��������� �����";
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

