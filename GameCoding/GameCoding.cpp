#include <iostream>
#include <list>
using namespace std;
#include "List.h"

int main()
{
	// 연결 리스트
	// size (resize)
	// 삽입/삭제?
	// - 시작	O(1)
	// - 중간	O(1) << 위치를 알고 있을 때
	// - 끝		O(1)
	// front		O(1)
	// back		O(1)
	// push_front		O(1)
	// push_back		O(1)	
	// 임의 접근 li[2] - 지원하지 않음

	list<int> li{ 1, 2, 3, 4, 5 };

	// 순회
	list<int>::iterator it;
	for (it = li.begin(); it != li.end(); it++)
	{
		int value = *it;
		// 값 탐색
		if (value == 3)
		{
			break;
		}
		cout << value << endl;
	}
	if (it != li.end()) // 원하는 값을 찾았을 때
	{

	}

	// 순회하면서 삭제하는 경우
	for (it = li.begin(); it != li.end(); it)
	{
		int value = *it;
		if (value % 2 == 0)
		{
			it = li.erase(it); // it은 다음 데이터 위치를 가리킴
		}
		else
			it++;
	}

	// 자체 제작 라이브러리
	List<int> l;
	l.AddAtTail(10);
	l.AddAtTail(20);
	l.AddAtTail(30);
	for (List<int>::iterator it = l.begin(); it != l.end(); it++)
	{
		int value = *it;
		cout << value << endl;
	}
	return 0;
}