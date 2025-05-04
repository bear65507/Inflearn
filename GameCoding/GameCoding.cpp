#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 함수 객체
// 함수 포인터의 단점
// - 시그니쳐가 안 맞으면 사용 불가
// - 상태(데이터)를 가질 수 없음(데이터랑 바인딩 불가)

class Functor
{
public:
	void operator() () // 괄호에 대한 오퍼레이터 오버로딩
	{
		cout << "Functor Test" << endl;
		cout << _value << endl;
	}

	void operator()(int n) // 오퍼레이터 오버로딩으로 시그니쳐 호환 문제 해결
	{
		cout << "Functor Test" << endl;
		cout << _value + n << endl;
	}
public:
	int _value = 0;
};

/* ------------------------------------------------------------ */
struct AddStruct
{
public:
	int operator()(int a, int b)
	{
		return a + b;
	}
};

template<typename T> // functor와 궁합이 좋다
int DoSomething(int a, int b, T func)
{
	return func(a, b);
}

template<typename T>
struct Greater
{
	bool operator()(const T& left, const T& right) const
	{
		return left > right;
	}
};

/* ------------------------------------------------------------- */

class Job
{
public:
	Job() { }
	virtual ~Job() { }
};

class MoveJob : public Job
{
public:
	MoveJob(int x, int y) : x(x), y(y) { }

	void operator()()
	{
		cout << "player move" << endl;
	}
public:
	int x;
	int y;
};

class AttackJob : public Job
{

};

int main()
{
	Functor func;
	func._value = 10;
	func(); // 어떤 상태를 저장한 다음에 어떤 동작까지 연이어 실행
	func(10);

	AddStruct func;
	DoSomething(10, 20, func);

	priority_queue<int, vector<int>, Greater<int>> pq;

	// 클라이언트 : (10, 20) 좌표로 이동할래
	MoveJob* job = new MoveJob(10, 20);
	AttackJob* attackjob = new AttackJob();
	(*job)();

	queue<Job>;


	return 0;
}