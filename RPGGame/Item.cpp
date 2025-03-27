#include "Item.h"
#include <iostream>
using namespace std;

Item::Item(ItemType itemtype)
	: _itemType(itemtype)
{
	int randValue = rand() % 100;

	if (randValue < 50)
	{
		_rarity = IR_Common;
	}
	else if (randValue < 80)
	{
		_rarity = IR_Rare;
	}
	else
	{
		_rarity = IR_Unique;
	}
}

Item::~Item()
{
}

void Item::PrintInfo()
{
	switch (_rarity)
	{
	case IR_Common:
		cout << "[��͵�] �Ϲ�" << endl;
		break;
	case IR_Rare:
		cout << "[��͵�] ����" << endl;
		break;
	case IR_Unique:
		cout << "[��͵�] ����ũ" << endl;
		break;
	}
}

Weapon::Weapon() : Item(IT_Weapon)
{
	switch (_rarity)
	{
	case IR_Common:
		_damage = 1 + rand() % 5;
		break;
	case IR_Rare:
		_damage = 10 + rand() % 5;
		break;
	case IR_Unique:
		_damage = 50 + rand() % 5;
		break;
	}
}

Weapon::~Weapon()
{
}

void Weapon::PrintInfo()
{
	cout << "********************" << endl;
	cout << "[������ Ÿ��] : ����" << endl;
	cout << "[���ݷ�] : " << _damage << endl;
	Item::PrintInfo();
	cout << "********************" << endl;
}

Armor::Armor() : Item(IT_Armor)
{
	switch (_rarity)
	{
	case IR_Common:
		_defence = 1 + rand() % 5;
		break;
	case IR_Rare:
		_defence = 2 + rand() % 5;
		break;
	case IR_Unique:
		_defence = 3 + rand() % 5;
		break;
	}
}

Armor::~Armor()
{
}

void Armor::PrintInfo()
{
	cout << "********************" << endl;
	cout << "[������ Ÿ��] : ��" << endl;
	cout << "[����] : " << _defence << endl;
	Item::PrintInfo();
	cout << "********************" << endl;
}
