#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

enum class ItemType
{
	None,
	Armor,
	Weapon,
	Jewelry,
	Consumable,
};

enum class Rarity
{
	Common,
	Rare,
	Unique
};

class Item
{
public:
	Item() {}
	Item(int itemid, Rarity rarity, ItemType type) : _itemid(itemid), _rarity(rarity), _type(type) { }

public:
	int _itemid = 0;
	Rarity _rarity = Rarity::Common;
	ItemType _type = ItemType::None;
};

class Knight
{
public:
	auto MakeResetHpJob()
	{
		auto job = [=]() // 캡쳐할 때 _hp가 아닌 this의 주소값을 복사해서 넘김
		{				// 복사라고 해서 무조건 안전한거 아님
				this->_hp = 200;
		};
		return job;
	}
public:
	int _hp = 100;
};

int main()
{
	// Lambda
	vector<Item> v;
	v.push_back(Item(1, Rarity::Common, ItemType::Weapon));
	v.push_back(Item(2, Rarity::Common, ItemType::Armor));
	v.push_back(Item(3, Rarity::Rare, ItemType::Jewelry));
	v.push_back(Item(4, Rarity::Unique, ItemType::Weapon));

	{
		// 람다
		// [](){} == [캡쳐모드](인자){구현부}
		// 익명함수라 이름이 필요없음
		// 1회용 함수(STD알고리즘 함수의 predicate 만들 때 유용) = 함수 객체와 유사한 부분이 많음
		auto isUniqueLambda = [](Item& item) { return item._rarity == Rarity::Unique; };

		[](Item& item) -> int // int로 타입을 지정
		{
				return item._rarity == Rarity::Unique;
		};

		std::find_if(v.begin(), v.end(), isUniqueLambda);

		// 람다함수안의 []안에 =, & --> 함수 밖에 있는 값을 가져옴
		// 기본 캡쳐 모드
		// = 복사, 복사한 값이 영구적으로 고정
		// & 참조, 원본과 동일한 값을 들고 있음
		int wantedId = 2;
		[=](Item& item) {return item._itemid == wantedId; };

		// 단일 변수마다 캡쳐모드
		[&wantedId](Item& item) {return item._itemid == wantedId; };

		std::find_if(v.begin(), v.end(), [&wantedId](Item& item) {return item._itemid == wantedId; });

	}

	// 람다함수의 캡쳐가 참조값을 들고 있을 땐 주소값이 유효한지 체크
	Knight* k = new Knight();
	k->_hp = 100;
	auto job = k->MakeResetHpJob();

	delete k;
	job(); // 이미 날라간 메모리에 접근하게 됨
	return 0;
}