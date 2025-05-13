#include <iostream>
#include <string>
using namespace std;

class Pet
{

};

class Knight
{
public:
	Knight()
	{

	}
	~Knight()
	{
		if (_pet)
			delete _pet;
	}
	// 복사생성자
	Knight(const Knight& other)
	{

	}
	// 복사 대입 연산자
	void operator=(const Knight& other)
	{
		_hp = other._hp;
		_pet = other._pet; // 동일한 원본 펫을 가리키는 문제
						 // 같은 메모리를 소멸시키려 하고 있음

		if (other._pet)
		{
			_pet = new Pet(*other._pet); // 새로운 펫을 만들어줘서 문제 회피
		}
	}

	// 이동 생성자
	Knight(Knight&& knight) noexcept
	{
		_hp = knight._hp;
		_pet = knight._pet; // 소유권을 이전, 상대방의 펫을 꺼내감
		knight._pet = nullptr;
	}
	// 이동 대입 연산자
	void operator=(Knight&& knight) noexcept
	{
		_hp = knight._hp;
		_pet = knight._pet; // 소유권을 이전, 상대방의 펫을 꺼내감
		knight._pet = nullptr;
	}
public:
	int _hp = 10;
	Pet* _pet = nullptr;
};

void TestKnight_Copy(Knight knight) // 복사 방식
{
	knight._hp = 100; // 원본에는 영향 X
}

void TestKnight_LValueRef(Knight& knight) // 왼값 참조 방식
{
	knight._hp = 100; // 원본(포인터, 주소값)을 넘겨주고 건드릴 수 있음
}

void TestKnight_ConstLValueRef(const Knight& knight) // const가 붙으면 오른값도 받아줄 수 있음
{
	// 원본을 넘겨주는데 건드릴 순 없음
}

void TestKnight_RValueRef(Knight&& knight) // &&는 오른값 참조
{
	// 원본을 넘겨주고 원본을 더 이상 사용하지 않음
}

int main()
{
	// C++11 3총사 : auto, lambda, rvalue-ref(오른값 참조)
	// 왼값(l-value) vs 오른값(r-value)
	// l-value : 단일식을 넘어서 계속 지속되는 개체
	// r-value : l-value가 아닌 나머지
	// 벡터에서 다른 벡터로 이사를 할 때 복사가 아닌 이동을 이용할 수 있음
	// 소유권 자체를 넘길 때?

	int a = 3; 
	a = 10; // a(식별자)는 단일식(선언부분)을 넘어서도 존재가능 = 왼값
	// 3 = 10; // 3(리터럴)은 단일식 넘어 존재 불가 = 오른값

	Knight k1;
	k1._pet = new Pet();

	Knight k2 = k1; // 복사 생성자
	k2 = k1; // 복사 대입 생성자

	Knight k3;
	k3 = static_cast<Knight&&>(k1); // k1의 펫을 가져감
	k3 = std::move(k1); // 위 코드와 같음 (rvalue_cast)

	TestKnight_Copy(k1);
	TestKnight_LValueRef(k1);
	TestKnight_ConstLValueRef(Knight()); // 임시 객체(오른값)
	TestKnight_RValueRef(Knight());

	TestKnight_RValueRef(static_cast<Knight&&>(k1)); // 왼값을 오른값으로 캐스팅

	
	return 0;
}