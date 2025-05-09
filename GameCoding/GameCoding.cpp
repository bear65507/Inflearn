#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

enum class ObjectType // dynamic_cast 대신 사용
{
	Player,
	Monster,
	Projectile,
	Env
};

class Object
{
public:
	Object(ObjectType type) : _type(type) {}
	virtual ~Object() { } // virtual(가상함수)가 없으면 RTTI가 없어서 가상함수 테이블을 못찾음

	ObjectType GetObjectType() { return _type; }
	// 시작
	virtual void Init()
	{

	}
	// 업데이트
	virtual void Update()
	{

	}
public:
	int _id;
	ObjectType _type;
};

class Player : public Object
{
public:
	Player() : Object(ObjectType::Player) { } // 상위 클래스의 생성자로 초기화
	Player(int id) : Object(id) { }
};

class Monster : public Object
{
public:
	Monster() : Object(ObjectType::Monster) { }
};

class Projectile : public Object 
{
	Projectile() : Object(ObjectType::Projectile) { }
};


class Field
{
public:
	static Field* GetInstance() // 싱글톤
	{
		static Field field;
		return &field;
	}

	void Update() {
		for (auto& item : _objects) // 모든 _objects 객체들을 순회
		{
			Object* obj = item.second;
			obj->Update();
		}
	}

	void Add(Object* player)
	{
		_objects.insert(make_pair(player->_id, player));
	}

	void Remove(int id)
	{
		_objects.erase(id);
	}

	Object* Get(int id)
	{
		auto findit = _objects.find(id);
		if (findit != _objects.end())
			return findit->second;

		return nullptr;
	}

private:
	//unordered_map<int, Player*> _players;
	//unordered_map<int, Monster*> _monsters;
	//unordered_map<int, Projectile*> _monsters;
	//unordered_map<int, Env*> _monsters;

	// 상위 클래스를 만들어 한곳에서 관리할 수도 있음
	unordered_map<int, Object*> _objects;
};

int main()
{
	/* 참고 */
	// Heap영역 [header(사이즈 정보, 데이터 정보][]
	int* ptr = new int[1000]; 
	delete[] ptr; // 데이터를 삭제할 때 몇 바이트인지 어떻게 아는가? --> Heap영역의 헤더 참고 

	// 1번 아이디가 플레이어인지
	// 방법 1 : enum
	Field::GetInstance()->Add(new Player(1));
	Object* obj = Field::GetInstance()->Get(1);
	if (obj and obj->GetObjectType() == ObjectType::Player)
	{
		Player* player = static_cast<Player*>(obj);
	}

	// 방법 2 : dynamic_cast<>
	Player* player = dynamic_cast<Player*>(Field::GetInstance()->Get(1)); // 가상함수 필요
	if (player)
	{

	}
	return 0;
}