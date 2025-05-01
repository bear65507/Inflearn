#include <iostream>
#include <vector>
using namespace std;

void CreateGraph_1() // 직관적이긴 하지만 잘 사용하지 않는 방법
{
	struct Vertex
	{
		// int data;
		vector<Vertex*> edges;
	};

	vector<Vertex> v(6); // 6개의 영역 확보
	/*
	// resize와 reverse 차이
	v.resize(6); // size와 연관 (push_back을 6번한 것과 동일)
	v.reserve(6); // capacity와 연관 (아직 데이터는 없지만 영역을 확보)
	*/

	// 0번에서 1번과 3번을 연결
	v[0].edges.push_back(&v[1]);
	v[0].edges.push_back(&v[3]);

	v[1].edges.push_back(&v[0]);
	v[1].edges.push_back(&v[2]);
	v[1].edges.push_back(&v[3]);

	v[3].edges.push_back(&v[4]);
	v[5].edges.push_back(&v[4]);

	// 0번과 3번이 연결되어 있는지 확인
	bool connected = false;
	int size = v[0].edges.size();
	for (int i = 0; i < size; i++)
	{
		Vertex* vertex = v[0].edges[i];
		if (vertex == &v[3])
		{
			connected = true;
		}
	}

}


void CreateGraph_2() // 인접 리스트를 활용 : 실제 연결된 애들'만' 넣어준다
{
	struct Vertex
	{
		int data;
	};

	vector<Vertex> v(6);

	vector<vector<int>> adjacent; // 이중 벡터, 각 정점의 연결 관계를 한 행에 넣어서 관리
	adjacent.resize(6); // 6개의 행 벡터 생성

	// 연결된 애들만 push_back
	adjacent[0] = { 1, 3 }; // 0번에서 1번과 3번을 연결 (초기값 설정)
	adjacent[1] = { 0, 2, 3 }; 
	adjacent[3] = { 4 };
	adjacent[5] = { 4 };

	// 0번에서 3번이 연결되어 있는지 확인
	bool connected = false;

	int size = adjacent[0].size();
	for (int i = 0; i < size; i++)
	{
		int vertex = adjacent[0][i];
		if (vertex == 3)
		{
			connected = true;
		}
	}
}

// 만약 정점이 100개라면?
// - 지하철 노선도 -> 서로 드문 드문 연결 -> 인접 리스트
// - 페이스북 친구 -> 서로 빽빽하게 연결 -> 인접 행렬
// 인접리스트 == 연결리스트와 비슷 / 인접 행렬 == 벡터와 비슷

// 인접 행렬
void CreateGraph_3()
{
	struct Vertex
	{
		int data;
	};

	vector<Vertex> v(6);

	// 연결된 목록을 행렬로 관리 
	// [X][O][X][O][X][X]
	// [O][X][O][O][X][X]
	// [X][X][X][X][X][X]
	// [X][X][X][X][O][X]
	// [X][X][X][X][X][X]
	// [X][X][X][X][O][X]

	// 6행 6열의 기본값이 false인 행렬 생성
	vector<vector<bool>> adjacent(6, vector<bool>(6, false));

	// adjacent[from][to] 
	// 행렬을 이용한 그래프 표현
	// 메모리 소모가 심하지만, 빠른 접근
	adjacent[0][1] = true; // 서로 연결된 애는 true로 변경
	adjacent[0][3] = true;
	adjacent[1][0] = true;
	adjacent[1][2] = true;
	adjacent[1][3] = true;
	adjacent[3][4] = true;
	adjacent[5][4] = true;

	// 0번과 3번이 연결되어 있는지 확인
	bool connected = adjacent[0][3];

	// 가중치 그래프 응용
	vector<vector<int>> abjacent2 =
	{
		{-1, 15, -1, 35, -1, -1},
		{15, -1, 5, 10, -1, -1},
		{-1, 5, -1, -1, -1, -1},
		{35, 10, -1, -1, 5, -1},
		{-1, -1, -1, 5, -1, 5},
		{-1, -1, -1, -1, 5, -1}
	};
	// -1은 끊김, 양수는 연결되어 있고 가중치 표현
}
// 그래프는 순회가 까다로움, 다음 정점으로 넘어가는 정교한 규칙이 필요
// -> BFS, DFS

int main()
{
	
	return 0;
}