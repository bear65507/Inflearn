#pragma once
#include "Enums.h"

class Item
{
protected:
	//Item();
	Item(ItemType itemtype);

public:
	virtual ~Item();
	virtual void PrintInfo();
	ItemType GetItemType() { return _itemType; }

protected:
	int _itemid = 0;
	int _itemCount = 0;
	ItemRarity _rarity = IR_Common;
	ItemType _itemType = IT_None;
};

class Weapon : public Item
{
public:
	Weapon();
	virtual ~Weapon();

	virtual void PrintInfo() override;

	void SetDamage(int damage) { _damage = damage; }
	int GetDamage() { return _damage; }

private:
	int _damage = 0;
};

class Armor : public Item
{
public:
	Armor();
	virtual ~Armor();

	virtual void PrintInfo() override;

	void SetDefence(int defence) { _defence = defence; }
	int GetDefence() { return _defence; }

private:
	int _defence = 0;
};

