#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

class Player
{
public:
	Player() {}
	Player(int id) : _id(id) {}


	int _id = 0;
};

template<typename T, typename U>
struct Pair // std::pair를 직접 구현
{
	T first;
	U second;
};

template<typename T, typename U> // std::make_pair를 직접 구현
auto MakePair(T first, U second) // 템플릿 문법과 auto를 활용한 형식 연역
{
	return std::pair<T, U>(first, second);
}


int main()
{
	vector<Player*> v;

	// 벡터에 객체를 넣어줌
	// 객체 자체를 넣기 보단 동적할당 해서 포인터로 들고 있게 하는게 좋음
	// --> 이동, 복사 비용을 아낌
	v.push_back(new Player(100));
	v.push_back(new Player(200));
	v.push_back(new Player(300));
	v.push_back(new Player(400));
	v.push_back(new Player(500));


	// 벡터에는 여러 한계가 있음, 따라서 (키, 값) 형태로 데이터를 저장하는 맵 사용
	map<int, Player*> m; // key를 int, value를 Player타입으로 저장

	// 데이터 추가 시 정렬되어 들어감 (레드-블랙 트리 처럼 균형 잡히게)
	/* 데이터 추가, 키와 값을 짝을 이뤄서 */
	for (Player* player : v)
	{
		m.insert(make_pair(player->_id, player));
		//m[player->_id] = player; // 바로 넣어주는 방법
	}

    /* 데이터 찾기, 정렬되어 있는 구조이기에 빠름(O(log N), 이진탐색과 비슷) */
	auto it = m.find(300); // 300을 찾고 순회자를 반환

	if (it != m.end()) // 데이터를 찾음
	{
		int key = it->first;
		Player* value = it->second;
		cout << "찾음" << endl;
	}
	else // 데이터 없음
	{
		cout << "없음" << endl;
	}
	Player* p = m[100]; // 키 값으로 접근해서 값을 꺼내옴
					  // 없는 키값으로 접근하면? C++에서는 없으면 기본값으로 추가

	/* 데이터 삭제 */
	m.erase(200);

	m.erase(it); // 순회자를 인자로 받는 버전

	/* 데이터 순회, 순회는 벡터가 더 유리함 */
	for (auto it = m.begin(); it != m.end(); it++)
	{
		int key = it->first;
		Player *p = it->second;
	}

	// C++ vector = C# List
	// C++ hash_map = C# Dictionary

	return 0;
}