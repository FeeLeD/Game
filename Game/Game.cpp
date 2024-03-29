// Game.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "Logic.h"
#include "MainCreature.h"
#include "Creature.h"
#include "string"
#include "iostream"
#include "Items.h"
#include "Weapon.h"
#include "Armor.h"
#include "Decoration.h"

using namespace std;

Logic game;
string name;

void Greetings(string name);
string GetFromUser(string info);

int main()
{
	setlocale(LC_ALL, "Russian");

	game.StartMessage();
	name = GetFromUser(name);
	Greetings(name);

	game.Help();
	game.FirstAction();

	string command = game.GetCommand();
	game.ProcessCommand(command);
}

void Greetings(string name)
{
	MainCreature mainHero(name);
	game.mainHero = mainHero;
	string message;
	message = "Приветствуем Вас ";
	message.append(name);
	cout << message << "! Перед началом путешествия ознакомтесь со справкой." << endl << endl;
}

string GetFromUser(string info)
{
	cin >> info;
	return info;
}


