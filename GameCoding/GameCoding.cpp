#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;


class Knight
{
public:
	~Knight() {
		cout << "Knight()" << endl;
	}
	void Attack()
	{
		// 사용하던 Knight 객체가 날라가지 않았는지 체크
		if (_target.expired() == false)
		{
			// 다시 shared_ptr로 사용 가능
			shared_ptr<Knight> spr = _target.lock();
		}
	}
public:
	int _hp = 100;
	int _damage = 10;
	weak_ptr<Knight> _target; 
};


int main()
{
	{
		shared_ptr<Knight> k1(new Knight);
		shared_ptr<Knight> k2(new Knight);

		// 스마트 포인터(shared_ptr)의 refCount가 0이 될 때 객체도 소멸
		k1->_target = k2;

		// 서로 바라보고 있으면 refCount가 낮아지지 않는 문제 (사이클 문제)
		// 메모리 누수 발생 (shared_ptr 자체로는 해결 불가)
		k2->_target = k1;
	}

	// weak_ptr : shared_ptr와 같이 사용(의존적임)
	//	- shared_ptr의 사이클 문제를 해결하기 위해 만들어짐

	// weak_ptr : refCount를 shared_ptr, weak_ptr가 이중 카운트로 관리
	// weak_ptr의 카운트가 shared_ptr의 카운트에는 영향을 주지 않음,
	//	= shared_ptr(어떤 객체를 참조하고 있는 수) / weak_ptr(객체가 소멸되었는지 체크)
	// weak_ptr의 카운트가 0이 아닌 이상(=객체가 날라가지 않았다면) 카운트 블럭(정보)은 유지
	// 카운트 블럭이 남아 있다면 shared_ptr로 재사용 가능

	/* ------------------------------------------------------------------------------------- */

	// unique_ptr
	// 하나만 존재하여야 하는 포인터, 복사 기능을 막아놓음

	unique_ptr<Knight> k1(new Knight());
	// unique_ptr<Knight> k2 = k1;

	// 오른값 참조로 k1을 이동시키는건 가능
	unique_ptr<Knight> k2 = std::move(k1);

	return 0;
}