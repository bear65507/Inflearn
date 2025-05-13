#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

//class ObjectManager // Use-After-Free 문제를 회피하는 하나의 방법
//{
//	Knight* GetObject(int id) // 객체의 id를 가지고 접근
//	{
//		return nullptr;
//	}
//
//	unordered_map<int, Knight*> um; // id와 객체를 세트로 관리 -> 해시 맵
//};

class Knight
{
public:
	~Knight() {}
	void Attack()
	{
		if (_target)
			_target->_hp = _damage;
	}
public:
	int _hp = 100;
	int _damage = 10;
	shared_ptr<Knight> _target = nullptr; // 주시 대상
	int targetid = 0; // 오브젝트 매니저와 아이디를 이용해서 찾기
};

/*--------------------- shared_ptr 구현 ------------------------------ */

class RefCountBlock // 실시간으로 refCount를 늘리는 작업을 쉽게 하기 위해
{
public:
	int refCount = 1;
};

template<typename T>
class SharedPtr // shared_ptr 구현
{
public:
	SharedPtr() {} 
	SharedPtr(T* ptr) : _ptr(ptr) 
	{
		if (ptr) // 관리하고 있는 포인터가 유효하면
		{
			_block = new RefCountBlock(); // refCount를 늘려줌
			cout << "RefCount: " << _block->refCount << endl;
		}
	}
	// SharedPtr이 복사되어 객체가 다른 객체와 같은 곳을 가리키고 있을 때
	SharedPtr(const SharedPtr& other) : _ptr(other._ptr), _block(other._block)
	{
		if (_ptr)
		{
			_block->refCount++;
		}
	}

	void operator=(const SharedPtr& other)
	{
		_ptr = other._ptr;
		_block = other._block;

		if (_ptr)
			_block->refCount++;
	}

	~SharedPtr()
	{
		if (_ptr) // 관리하고 있는 포인터가 있었을 때
		{
			_block->refCount--;

			// 이제 SharedPtr을 사용하는 포인터가 없을 때
			if (_block->refCount == 0)
			{
				delete _ptr;
				delete _block;
				cout << "Delete Data" << endl;
			}
		}
	}
public:
	T* _ptr = nullptr; 
	RefCountBlock* _block = nullptr; // shared_ptr를 참조하는 객체 수 관리
};

void Test(shared_ptr<Knight>& knight)
{
	// 간혹 함수에 shared_ptr의 참조값을 넘기는 경우가 있는데,
	// refCount를 증감시키는 비용을 아낄 수 있음
}

/* ------------------------------------------------------------------------- */
template<typename T>
class Wrapper // 래퍼 클래스
{
public:
	Wrapper(T* ptr) : _ptr(ptr) {} // 관리해줄 포인터를 받아줌
	~Wrapper() // 래퍼 클래스가 소멸될 때 관리하고 있던 포인터를 소멸시켜줌
	{
		if (_ptr)
			delete _ptr;
	}
public:
	T* _ptr;
};


int main()
{
	{
		Wrapper<Knight> w(new Knight()); // 래퍼 클래스에 나이트를 넣어서 관리
		// 나이트를 따로 delete 시켜주지 않아도 됨
	}
	/*  --------------------------------------------------------------------  */

	// 스마트 포인터 : 포인터를 생으로 관리하지 않고 추가적으로 뭔가 만들어줘서 관리
	// shared_ptr : 비중이 제일 높음
	// weak_ptr
	// unique_ptr
	
	// shared_ptr = 내부적으로 refCount를 추적해서 나를 기억하고 있는 애(포인터)가 몇명인지 추적
	// 일반 포인터와 사용방법은 같음
	// shared_ptr을 더 이상 사용하는 포인터가 없을 때(refCount가 0일 때), 비로소 shared_ptr가 소멸


	{
		Knight* k1 = new Knight(); // 클래스긴 하지만 하나의 포인터
		Knight* k3;
		k3 = k1; // k3, k1가 같은 주소를 가리키고 있음
	}

	{
		// 위의 코드와 의미가 같음

		SharedPtr<Knight> k1(new Knight());
		//SharedPtr<Knight> k2(new Knight());

		SharedPtr<Knight> k3;
		k3 = k1; // SharedPtr을 복사, 얕은 복사
		// 내부적으로는 참조값을 그대로 넘겨줌, 같은 주소를 참조하는 객체가 하나 늘어남
	}

	/* 
	k1->_target = k2;
	delete k2; // ???
	k1->Attack(); // 접근하면 안되는 메모리 공간에 접근 중, 메모리 오염이 일어남(Use-After-Free)
	*/

	/*  ----------------------------------------------------------------------------------  */

	// shared_ptr는 생 포인터와 섞어쓸수 없음
	shared_ptr<Knight> k1(new Knight);
	shared_ptr<Knight> k2(new Knight);
	k1->_target = k2; // k2를 기억하고 있는 포인터가 늘어났기 때문에 k2의 refCount가 늘어남
	// k2가 소멸되어도 k1의 _target은 k2를 기억하고 있음

	return 0;
}