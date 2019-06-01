#include "Items.h"
#include "cstdlib"
#include "ctime"
#pragma once
enum DType { AMULET, MASCOT, RING, PENDANT };
class Decoration : public Items
{
private:
	int WhatToBuff() {
		srand(unsigned int(time(0)));
		int random = rand();
		int position = rand() % 4;
		return position;
	};
	double GetCoficient(IType it) {
		double buff;
		switch (it)
		{
		case USUAL: buff = 1.1;
			break;
		case RARE: buff = 1.2;
			break;
		case LEGENDARY: buff = 1.3;
			break;
		default:
			break;
		}
		return buff;
	};
	string GetName(DType dt, int pos, int c) {
		string result;
		switch (dt)
		{
		case AMULET: 
			result = "������ +";
		case MASCOT:
			result = "�������� +";
		case RING:
			result = "������ +";
		case PENDANT:
			result = "����� +";
		default:
			break;
		}

		string percents;
		if (c == 1.1)
			percents = "10";
		else if (c == 1.2)
			percents = "20";
		else
			percents = "30";

		switch (pos)
		{
		case 0:
			result.append(percents);
			result.append(" % � ��������");
			break;
		case 1:
			result.append(percents);
			result.append(" % � �����");
			break;
		case 2:
			result.append(percents);
			result.append(" % � �����");
			break;
		case 3:
			result.append(percents);
			result.append(" % � �������");
			break;
		default:
			break;
		}

		return result;
	};
public:
	bool on;
	int buffNumber;
	double coficient;
	DType dtype;
	Decoration(IType it, DType dt);
	Decoration();
};

