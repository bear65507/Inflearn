#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

// (☆)메모리를 팔아서 (CPU)성능을 얻겠다

// ex) 아파트 우편함
// [201][202][203][204]
// [101][102][103][104]
// 203호 우편 --> 바로 접근 = O(1)

// 키를 알면 빠르게 찾을 수 있다 O(1)
// -> hash 기법
// 보안 업계에서 주로 사용, 비밀번호를 해시 알고리즘으로 암호화해서 저장,
// 해시값만 알고는 비밀번호를 알 수 없다(단방향)
// == 단방향으로 유니크한 키를 꺼내는 기법

// 복잡한 값이라도 해시를 취해서 키값을 추출한다음 특정 칸(버킷)에 데이터를 넣어준다
// ex) 아이디 % 10000 = 키
// [1][2][3]...[10000]
// hash(100002324024120002) -> 2 
// -> 2번째 칸(버킷)에 저장


int main()
{
	// hash_map
	// 탐색의 시간복잡도 : O(1)
	unordered_map<int, int> um;

	// 삽입/삭제, 탐색, 순회가 map과 비슷
	// 삽입
	um.insert(make_pair(10, 100));
	um[20] = 200;

	// 찾기
	auto findit = um.find(10);
	if (findit != um.end())
	{
		cout << "찾음" << endl;
	}
	else
	{
		cout << "없음" << endl;
	}

	// 삭제
	um.erase(10);
	//um.erase(findit);

	// 순회
	for (auto it = um.begin(); it != um.end(); it++)
	{
		int key = it->first;
		int value = it->second;
	}

	return 0;
}