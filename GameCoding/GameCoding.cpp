#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void Print()
{
	cout << "Hello, World!" << endl;
}

int Add(int a, int b)
{
	return a + b;
}

// 콜백 함수 : 어떤 행동을 했을 때 역으로 함수를 호출해 주는 것
// ex) UI : 어떤 버튼을 눌렀을 때 함수 호출 / ex) 키보드 입력 

// '행동' 자체를 인자로 넘기고 싶을 때
using FuncPtrType = int(*)(int a, int b);

int DoSomething(int a, int b, FuncPtrType func)
{
	return func(a, b);
}

class Item
{
public:

public:
	int _itemid = 0;
	int _rarity = 0;
	int _ownerid = 0;
};

/*  -------------------------------------------------------------------------------- */
using ItemSelectorType = bool(*)(Item* item);

// 각 조건마다 함수 자체를 넣어 처리하면 코드가 너무 방대해짐 --> 함수 포인터 사용
Item* FindItem(Item items[], int itemCount, ItemSelectorType selector)
{
	for (int i = 0; i < itemCount; i++) // 모든 아이템들을 순회
	{
		Item* item = &items[i];
		if (selector(item)) // IsRare(item)
			return item;
	}

	return nullptr;
}

bool IsRare(Item* item)
{
	return item->_rarity == 1;
}
/* ----------------------------------------------------------------------------------- */
// 멤버 함수 포인터
class Test
{
public:
	void PrintTest(){ }
};


int main()
{
	using DataType = int;

	/* 잘 안 쓰이는 문법 (쓰임새 없음)
	using FuncType = void(); // = void를 입력으로 받는 함수를 FuncType으로 부르겠다(시그니쳐)
	FuncType* ptr = &Print; // 함수 포인터, 주소값 변수(&)는 생략가능
	ptr(); // 함수의 주소를 타고 가서 함수를 실행

	using FuncType2 = int(int, int); // int 타입을 반환하고 int 2개를 입력으로 받는 함수를
								  // FuncType2로 부르겠다(시그니쳐)
	FuncType2* ptr2 = &Add;
	int ret = ptr2(10, 20); // 시그니쳐에 맞추기
	*/

	using FuncPtrType = void(*)(); // void를 뱉어주고 void를 받아주는 함수의 포인터타입인
								// FuncPtrType을 선언 (현대 문법)
	FuncPtrType ptr = &Print;
	ptr();

	DoSomething(10, 20, &Add);
	DoSomething(10, 20, [](int a, int b) { return a - b; }); // 람다 함수 (익명 함수)

	Item items[10];
	items[3]._rarity = 1; 
	FindItem(items, 10, IsRare); // rarity가 1인 아이템 찾기

	// 멤버함수 포인터 (정적/전역 함수랑 다르다) --> 기존 방법으론 사용 불가
	// 함수 호출 규약이 다름
	// (함수를 호출할 때 전달되는 인자들의 순서나 함수 종료 시 누가 함수를 정리하는 지)
	using MemFuncPtrType = void(Test::*)();
	MemFuncPtrType funcPtr = &Test::PrintTest;
	
	Test t;
	(t.*funcPtr)();
	Test* t2 = &t;
	(t2->PrintTest)();

	return 0;
}