#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void Test(vector<int>& v) // 참조에 의한 전달 (원본 값)
{

}

int main()
{
	vector<int> v{ 1, 2, 3, 4, 5 };
	// size (resize) == 실제 데이터 크기
	// capacity (reserve) == 실제로 사용할(할당된) 공간
	// 삽입/삭제
	// - 시작   O(N)
	// - 중간   O(N)
	// - 끝     O(1)
	// push_back, front, back
	// 임의 접근 v[i]   O(1)

	int a = v.front(); // O(1)
	int b = v.back();  // O(1)

	// 순회
	const int size = v.size(); // size()함수를 반복적으로 호출하는 비용을 아끼고 싶을 때
	for (int i = 0; i < size; i++)
	{
		cout << v[i] << endl;
	}

	// 초기화
	vector<int> v2(5); // 데이터 개수
	vector<int> v3(5, -1); // 데이터 개수, 초기값
	vector<int> v4{ 1, 2, 3, 4, 5 }; // 원하는 데이터로 채움

	// 벡터라는 클래스 자체는 stack에 있지만 실제 데이터는 heap 영역에 들어가 있음
	vector<int> v5 = v4;
	v5[0] = 100; // 얕은(간접적인) 복사

	// clear()
	v.clear();
	cout << v.size() << endl; // size는 0
	cout << v.capacity() << endl; // capacity는 변하지 않음

	// iterator : 반복자, 순회자 (포인터 개념)
	{
		vector<int> v{ 1, 2, 3, 4, 5 };
		int* ptr = &v[0]; // 첫번째 데이터에 접근
		int value = *ptr; // 데이터 추출

		ptr++; // 다음 데이터로 넘어가기
		ptr += 2; // 다다음 데이터로 넘어가기
		ptr = &v[0];

		int* ptrEnd = &v[4] + 1; // 마지막 데이터 다음을 가리키도록 유도
		while (ptr != ptrEnd) // 모든 데이터 순회
		{
			cout << *ptr << endl;
			ptr++;
		}
	}

	// STL 제공 순회자 사용
	{
		vector<int> v{ 1,2,3,4,5 };

		vector<int>::iterator it = v.begin();
		vector<int>::iterator itEnd = v.end();

		for (it; it != itEnd; it++)
		{
			int data = *it;
			if (data == 3) // 벡터 안에 3이 있는지?
			{
				// 찾음
				break;
			}
			cout << data << endl;
		}

		if (it == v.end())
		{
			// 데이터 못찾음
		}

		// 데이터 삭제
		if (it != v.end())
		{
			v.erase(it); // 3 삭제
		}
	}

	// 모든 데이터들을 순회하며 특정 조건에 따라서 실시간으로 삭제
	{
		vector<int> v{ 1,2,3,4,5 };
		vector<int>::iterator it;
		for (it = v.begin(); it != v.end(); it) // it++하면 안됨
		{
			// 짝수인 데이터 삭제
			int value = *it;
			if (value % 2 == 0)
				it = v.erase(it); // 삭제된 위치의 순회자를 다음 위치로 갱신
			else 
				// 순회를 하며 삭제하는 경우, erase()할 때와 아닐때를 구분해서 만들어야 함
				it++; 
		}
	}

	return 0;
}