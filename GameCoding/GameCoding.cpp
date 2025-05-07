#include <iostream>
#include <vector>
using namespace std;

// 이진 탐색 (binary search)

vector<int> numbers;

void BinarySearch(int N)
{
	// 재귀함수 또는 while문으로 접근
	int left = 0; 
	int right = numbers.size() - 1; // 시작 인덱스와 끝 인덱스

	while (left <= right)
	{
		cout << "탐색 범위 : " << left << "~" << right << endl;

		int mid = (left + right) / 2; // 중간 위치 (소수점 버림)

		if (N < numbers[mid]) // N이 중간값보다 작으면, 중간 위치에서 왼쪽을 탐색
		{
			cout << N << " < " << numbers[mid] << endl;
			right = mid - 1;
		}
		else if (N > numbers[mid]) // N이 중간값보다 크면, 오른쪽을 탐색
		{
			cout << N << " > " << numbers[mid] << endl;
			left = mid + 1;
		}
		else // 값을 찾음
		{
			cout << "찾았음!" << endl;
			break;
		}
	}
}

int main()
{
	// [1][8][15][23][32][44][56][63][81][91]
	// Q) 82가 있는가?
	// 일일이 스캔(순차탐색) - O(N) 
	// 
	// 배열이 정렬되어 있을 시 -> 중간값 체크
	// 82보다 크면, 왼쪽을 보고 / 82보다 작으면, 오른쪽을 본다
	// 이진 탐색 = O(log N)

	numbers = { 1, 8, 15, 23, 32, 44, 56, 63, 81, 91 };
	BinarySearch(28);

	// 연결 리스트로는 원소에 임의 접근이 안되기 때문에 이진 탐색을 할 수 없음 
	// 배열로는 중간 위치에 삽입/삭제가 느리다 O(N)
	// --> 데이터가 유동적으로 변화하는 환경에서는 이진 탐색이 불리
	// --> 대안 : 트리 구조

	return 0;
}