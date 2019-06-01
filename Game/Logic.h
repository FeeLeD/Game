#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <fstream>
#include <iterator>
#include "math.h"
#include "cstdlib"
#include "ctime" 
#include "Location.h"
#include "Creature.h"
#include "MainCreature.h"
#include "Monster.h"
#include "Items.h"
#include "Weapon.h"
#include "Armor.h"
#include "Decoration.h"
#pragma once
using std::ifstream;
using std::istreambuf_iterator;
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::remove;

class Logic
{
private:
	int attackRange;
	int defenceRange;
	int monsterHP;
	int userHP;
	int monsterHtP;
	int userHtP;

	vector<int> actionsPassed;
	vector<string> actionsNumbers;
	int randomRange = 5;
	bool first = true;
	bool canMoveOn = true;

	int GerRandomNumber(int rndmRange) {
		srand(unsigned int(time(0)));
		int randomNumber = rand();
		int position = rand() % rndmRange;
		return position;
	};
	vector <string> GetActNumber() {
		if (location.ltype == LType::DEEPFOREST) {
			vector<string> numbers{ "1", "2", "3", "4", "5" };
			return numbers;
		};
		if (location.ltype == LType::GIANTDRAWINGS) {
			vector<string> numbers{ "6", "7", "8", "9", "10" };
			return numbers;
		};
		if (location.ltype == LType::CURVEDGROUND) {
			vector<string> numbers{ "11", "12", "13", "14", "15" };
			return numbers;
		};
	};
	string ReadFile(string path) {
		ifstream ifs(path);
		if (ifs.is_open())
		{
			string message;
			message.assign((istreambuf_iterator<char>(ifs.rdbuf())), istreambuf_iterator<char>());
			ifs.close();
			return message;
		}
		else
		{
			cout << "�� ��� ������� ����� �������!" << endl;
			return 0;
		}
	};

	bool AlreadyPassed(int number) {
		int n = number;
		for each (int act in actionsPassed)
		{
			if (act == n)
				return true;
		};
		return false;
	};

	bool ChooseDirection() {
		string direction;
		cout << "�������� �����������(left, forward, right): ";
		cin >> direction;
		if (direction == "left" || direction == "forward" || direction == "right") {
			return true;
		}
		else {
			cout << "������� ���������� �������! ��� ������� �������: help" << endl;
			ChooseDirection();
		};
	};

	void CommandMove() {
		string text;
		if (first) {
			first = false;
			text = ReadFile("plot/actions/act0.txt");
			cout << text;
			ProcessCommand(GetCommand());
		};
		cout << endl;
		ChooseDirection();

		int position = GerRandomNumber(randomRange);
		string actNumber = actionsNumbers[position];
		int number = stoi(actNumber);
		while (AlreadyPassed(number)) {
			if (actionsNumbers.empty())
				GameOver();
			else {
				actionsNumbers.erase(remove(actionsNumbers.begin(), actionsNumbers.end(), actNumber), actionsNumbers.end());
				randomRange--;
				position = GerRandomNumber(randomRange);
				actNumber = actionsNumbers[position];
				number = stoi(actNumber);
			};
		}

		string path = "plot/actions/act";
		path.append(actNumber);
		path.append(".txt");
		text = ReadFile(path);
		cout << text;

		if (actNumber == "5") {
			actionsPassed.push_back(stoi(actNumber));
			canMoveOn = true;
			if (actionsPassed.size() == 5)
				GameOver();
			else
				ProcessCommand(GetCommand());
		}
		else {
			canMoveOn = false;
			GetBFAnswer(actNumber);
		};
	};

	void GetBFAnswer(string actNumber) {
		string command;
		cin >> command;
		if (command == "yes" || command == "no") {
			actionsPassed.push_back(stoi(actNumber));
			if (command == "yes")
				Fight();
			else {
				if (actionsPassed.size() == 5)
					GameOver();
				else {
					cout << "����� �� ����! �� ������ ��������� ���� ���������, ������ �������������..." << endl << "���� ��������: ";
					canMoveOn = true;
					ProcessCommand(GetCommand());
				};
			}
		}
		else {
			cout << "������� ���������� ����� (yes/no)!: ";
			GetBFAnswer(actNumber);
		};
	};

	void CommandItems() {
		cout << endl << "������ ����� ���������:" << endl;
		for each (Decoration dec in mainHero.backpack)
		{
			cout << "#" << dec.name << ";" << endl;
		}
		cout << "������� �� �� �������� ���������?: ";
		GetBPAnswer();
	};

	void GetBPAnswer() {
		string command;
		cin >> command;
		if (command == "yes") {
			if (IsEmptyBack()) {
				cout << "� ��� ������ ��������..." << endl << "������� ��������� �������: ";
				ProcessCommand(GetCommand());
			};
			//���������� ��� ��������� ���������...
		}
		else if (command == "no") {
			cout << "������� ��������� �������: ";
			ProcessCommand(GetCommand());
		}
		else {
			cout << "������� ���������� ����� (yes/no)!: ";
			GetBPAnswer();
		};
	};

	bool IsEmptyBack() {
		int check = 0;
		for each (Decoration dec in mainHero.backpack)
		{
			if (dec.name == "�����")
				check++;
			if (check == 3)
				return true;
		}
		return false;
	};

	void CommandStats() {
		cout << endl;
		cout << "���� ����������:" << endl;
		cout << "# " << "���� ����������: " << mainHero.name << endl;
		cout << "# " << "���������� ��������: " << mainHero.healthPoints << " HP" << endl;
		cout << "# " << "�����: " << mainHero.armor.name << endl;
		cout << "# " << "�������� �����: " << mainHero.armorPoints << " AP" << endl;
		cout << "# " << "���� ������: " << mainHero.weapon.name << endl;
		cout << "# " << "��� ����: " << mainHero.hitPoints << " HtP" << endl;
		cout << "# " << "��� ����: " << mainHero.experience << " XP" << endl;
		cout << "# " << "��� �������: " << mainHero.level << " LVL" << endl;
		cout << "# " << "���������� ���������: " << mainHero.fightsNumber << endl;
		cout << "================================" << endl << endl;
		cout << "������� ���� ���������� ��������: ";
		ProcessCommand(GetCommand());
	};

	void Fight() {
		Monster monster(location.ltype, mainHero);
		attackRange = monster.attackRange;
		defenceRange = monster.defenceRange;
		monsterHP = monster.healthPoints;
		userHP = mainHero.healthPoints;
		monsterHtP = monster.hitPoints;
		userHtP = mainHero.hitPoints;
		ShowMonster�haracteristic(monster);
		cout << "��� �������!" << endl << "������ ����� ���������� ���� �������� ������� ������ ����!" << endl;
		if (IsUserFirst()) {
			while(true) {
				Attack();
				if (monsterHP <= 0)
					break;
				Defence();
				if (userHP <= 0)
					GameOver();
			};
		}
		else {
			while (true) {
				Defence();
				if (userHP <= 0) 
					GameOver();
				Attack();
				if (monsterHP <= 0)
					break;
			};
		};
		ProcessCommand(GetCommand());
	};

	void Attack() {
		int compNumber = GerRandomNumber(attackRange);
		int userNumber;
		cout << "��� ���� (������� ����� �� 0 �� " << attackRange - 1 << "): ";
		cin >> userNumber;
		while (userNumber > (attackRange - 1) || userNumber < 0)
		{
			cout << "������� ����� � ������ ���������! ( �� 0 �� " << attackRange - 1 << "):";
			cin >> userNumber;
		} 
		int result = abs(userNumber - compNumber);
		switch (result)
		{
		case 0: monsterHP -= userHtP;
			cout << "�������! �� ������� ������������ ���� - " << userHtP << " HtP" << endl;
			break;
		case 1: monsterHP -= (userHtP * 0.9);
			cout << "������! �� ������� 90% �� ������������� ����� - " << userHtP * 0.9 << " HtP" << endl;
			break;
		case 2: monsterHP -= (userHtP * 0.8);
			cout << "�������! �� ������� 80% �� ������������� ����� - " << userHtP * 0.8 << " HtP" << endl;
			break;
		case 3: monsterHP -= (userHtP * 0.7);
			cout << "�������! �� ������� 70% �� ������������� ����� - " << userHtP * 0.7 << " HtP" << endl;
			break;
		case 4: monsterHP -= (userHtP * 0.5);
			cout << "�����! �� ������� 50% �� ������������� ����� - " << userHtP * 0.5 << " HtP" << endl;
			break;
		case 5: monsterHP -= (userHtP * 0.2);
			cout << "������� ������! �� ������� 20% �� ������������� ����� - " << userHtP * 0.2 << " HtP" << endl;
		default:
			cout << "������! �� �� ����� �����������" << endl;
			break;
		}
		if (monsterHP <= 0) {
			mainHero.experience += 50;
			mainHero.CheckLevel();
			mainHero.fightsNumber += 1;
			cout << "���� ��������!" << endl;
			CheckWin();
			cout << "���� ���� ������. ��������� ���� ���������� (����� ������ ������������ ����). ������� ���� ���������� ��������: ";

		}
		else {
			cout << "�������� �����: " << monsterHP << endl;
		}
	};

	void Defence() {
		int compNumber = GerRandomNumber(defenceRange);
		int userNumber;
		cout << "���� �������� ������� ����. �����������! (������� ����� �� 0 �� " << defenceRange - 1 << "): ";
		cin >> userNumber;
		while (userNumber > (defenceRange - 1) || userNumber < 0)
		{
			cout << "������� ����� � ������ ���������! ( �� 0 �� " << defenceRange - 1 << "):";
			cin >> userNumber;
		}
		int result = abs(userNumber - compNumber);
		switch (result)
		{
		case 0:
			cout << "�������! ��� ������� ���������� �� ���������� �����!" << endl;
			break;
		case 1: userHP -= (monsterHtP * 0.1);
			cout << "������! �� ����� ����������! ���� ���� ����� ���� 10% �� ������ ������������� ����� - " << monsterHtP * 0.1 << " HtP" << endl;
			break;
		case 2: userHP -= (monsterHtP * 0.2);
			cout << "�������! ���� ���� ������� ����� ���� 20% �� ������ ������������� ����� - " << monsterHtP * 0.2 << " HtP" << endl;
			break;
		case 3: userHP -= (monsterHtP * 0.3);
			cout << "�������! �� ������� �� ���� ����� ���� 30% �� ������������� ����� ����� - " << monsterHtP * 0.3 << " HtP" << endl;
			break;
		case 4: userHP -= (monsterHtP * 0.5);
			cout << "���� ������� ��� �������! �� �������� 50% �� ��� ������������� ����� - " << monsterHtP * 0.5 << " HtP" << endl;
			break;
		case 5: userHP -= (monsterHtP * 0.8);
			cout << "��! ����� ���������, ���� ���� 80% �� ������ ������������� ����� - " << monsterHtP * 0.8 << " HtP" << endl;
		default: userHP -= (monsterHtP);
			cout << "���� ������������ ���. �� �������� ������������ ���� - " << monsterHtP << " HtP" << endl;
			break;
		}
		if (userHP <= 0) {
			cout << "���� ������� ������. ���� ��������..." << endl;
			Killed();
		}
		else {
			cout << "���� ��������: " << userHP << endl;
		}
	};

	bool IsUserFirst() {
		cout << "������� ����� 0 ��� 1: ";
		int compNumber = GerRandomNumber(2);
		int userNumber;
		cin >> userNumber;
		if (userNumber == compNumber) {
			cout << "�� �������� ���� ������!" << endl;
			return true;
		}
		cout << "��� �� ������� ����������� ����������, ���� ���� ������" << endl;
		return false;
	};

	void ShowMonster�haracteristic(Monster monster) {
		cout << endl << "�� ���������� � " << monster.name << "!" << endl;
		cout << "�������������� �������:" << endl;
		cout << "# ��������: " << monster.healthPoints << " HP" << endl;
		cout << "# �����: " << monster.armorPoints << " AP" << endl;
		cout << "# �����: " << monster.hitPoints << " HtP" << endl;
		cout << "# �������� ����� ��� ��������� �� �������: �� 0 �� " << monster.attackRange - 1 << endl;
		cout << "# �������� ����� ��� ������ �� ���������: �� 0 �� " << monster.defenceRange - 1 << endl;
		cout << "====================================================" << endl << endl;
	};

	void CheckWin() {
		if (mainHero.fightsNumber == 3) {
			string text;
			text = ReadFile("plot/win.txt");
			cout << text;
			cout << "���� ����������:" << endl;
			cout << "# " << "���� ����������: " << mainHero.name << endl;
			cout << "# " << "���������� ��������: " << mainHero.healthPoints << " HP" << endl;
			cout << "# " << "�����: " << mainHero.armor.name << endl;
			cout << "# " << "�������� �����: " << mainHero.armorPoints << " AP" << endl;
			cout << "# " << "���� ������: " << mainHero.weapon.name << endl;
			cout << "# " << "��� ����: " << mainHero.hitPoints << " HtP" << endl;
			cout << "# " << "��� ����: " << mainHero.experience << " XP" << endl;
			cout << "# " << "��� �������: " << mainHero.level << " LVL" << endl;
			cout << "# " << "���������� ���������: " << mainHero.fightsNumber << endl;
			cout << "================================" << endl << endl;
			exit(0);
		};
	};

public:
	Logic();
	MainCreature mainHero;
	Location location;

	void StartMessage() {
		string text;
		text = ReadFile("plot/intro.txt");
		cout << text;
	};

	void Help() {
		string text;
		text = ReadFile("plot/help.txt");
		cout << text << endl << endl;
	};

	void FirstAction() {
		string text;
		text = ReadFile("plot/firstAct.txt");
		cout << text;
	};

	string GetCommand() {
		string command;
		cin >> command;
		return command;
	};

	void ProcessCommand(string command) {
		if (command == "move") {
			if (canMoveOn)
				CommandMove();
		}
		else if (command == "items") {
			CommandItems();
		}
		else if (command == "help") {
			Help();
			cout << "������� ���������� �������: ";
			ProcessCommand(GetCommand());
		}
		else if (command == "stats") {
			CommandStats();
		}
		else {
			cout << "������� ���������� �������! ��� ������� �������: help" << endl;
			ProcessCommand(GetCommand());
		};
	};

	void GameOver() {
		string text;
		text = ReadFile("plot/lost.txt");
		cout << endl << text;
		exit(0);
	};

	void Killed() {
		string text;
		text = ReadFile("plot/killed.txt");
		cout << endl << text;
		exit(0);
	};
};

