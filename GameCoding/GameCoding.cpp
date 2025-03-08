#include <iostream>
using namespace std;

class Player
{
public:
	Player()
	{
		cout << "Player()" << endl;
	}

	~Player()
	{
		cout << "~Player()" << endl;
	}
};

class Inventory
{
public:
	Inventory() : _a(10)
	{
		cout << "Inventory()" << endl;
	}
	Inventory(int a)
	{
		_a = a;
		cout << "Inventory(int)" << endl;
	}
	~Inventory()
	{
		cout << "~Inventory()" << endl;
	}
public:
	int _a;
};

class Knight : public Player
{
public:
	Knight() : _hp(0)
	/*
	* 선처리 영역
	*/
	{
		_hp = 0;
		cout << "Knight()" << endl;
	}

	~Knight()
	{
		cout << "~Knight()" << endl;
	}

public:
	int _hp = 0;

	int& _hpRef = _hp;
	const int _hpconst = _hp;;
};

int main()
{
	for (int i = 0; i < 4; i++)
	{
		Knight k1;
		cout << k1._hp << endl;
	}

		Knight k2;
		for (int i = 0; i < 4; i++)
		{
			cout << k2._hp << endl;
		}

		{
			Knight k3;
			for (int i = 0; i < 4; i++)
			{
				cout << k3._hp << endl;
			}
		}
}