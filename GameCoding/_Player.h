#pragma once
class Player
{
public:
	void Attack() { cout << "Attack" << endl; }
	void Die() { cout << "Die" << endl; }
	void HealMe(int value)
	{
		_hp += 10;
	}
public:
	int _hp;
	int _attack;
	int _defence;
};
