#include <iostream>
#include <windows.h>
using namespace std;

// 메모이제이션 (memeoizaion)
// 캐시를 만들어 저장하고 찾아서 사용한다
int cache[50][50];

int Combination(int n, int r)
{
	// 기저 조건
	if (r == 0 or n == r)
		return 1;

	// 이미 답을 구한 적 있으면 바로 반환
	int& ret = cache[n][r]; // 참조값으로 들고 있는게 나음
	if (ret != -1)
		return ret;

	return ret = Combination(n - 1, r - 1) + Combination(n - 1, r);
}

/* 인챈트 문제 
	+0 집행검
	무기 강화 주문서 -> +1, +2, +3 중 하나
	
	+9 집행검이 뜨는 경우의 수는?
	ex) +1 +2 +3 ... +9
	ex) +3 +6 +9
	ex) +1 +3 +4 ... +9
*/

int N = 9;
int cache2[100];

// [+num]부터 시작해서, [+N]까지 가는 경우의 수
int Enchant(int num)
{
	// 기저 조건
	if (num > N)
		return 0;
	if (num == N)
		return 1;
	// 캐시
	int& ret = cache2[num];
	if (ret != -1)
		return ret;
	// 조건 : 0강부터 시작해서 +1, +2, +3강씩 강화시키고, 9강이 되는 횟수를 구함
	return ret = Enchant(num + 1) + Enchant(num + 2) + Enchant(num + 3);
}

int main()
{
	/*
	::memset(cache, -1, sizeof(cache)); // 캐시 배열을 -1로 초기화

	__int64 start = GetTickCount64();

	int lotto = Combination(45, 6);

	__int64 end = GetTickCount64();

	cout << end - start << "ms" << endl;
	*/

	memset(cache2, -1, sizeof(cache2));
	int ret = Enchant(0);
	cout << ret << endl;

	return 0;
}