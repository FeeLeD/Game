#include "string"
using std::string;
const int SIZE = 10;
#pragma once
enum IType { USUAL, RARE, LEGENDARY };
class Items
{
public:
	IType itype;
	string name;
};

