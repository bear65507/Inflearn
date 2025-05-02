#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// DFS (Depth First Search) == 시작점으로 기준으로 얼마나 깊이 들어가는가
// DFS = 재귀함수, 트리와 다르게 양방향으로 이동할 수 있음을 고려 = 또는 스택으로 구현
// BFS (Breath First Search) 너비
// BFS = 큐

struct Vertex
{
	// int data;
};

vector<Vertex> vertices;
vector<vector<int>> adjacent;

// 내가 방문한 목록(DFS)
vector<bool> visited;

// 내가 발견한 목록(BFS)
vector<bool> discovered;

void CreateGraph()
{
	vertices.resize(6);

	
	// 인접 리스트
	/*
	adjacent = vector<vector<int>>(6);
	adjacent[0] = { 1, 3 };
	adjacent[1] = { 0, 2, 3 };
	adjacent[3] = { 4 };
	adjacent[5] = { 4 };
	*/

	// 인접 행렬
	adjacent = vector<vector<int>>
	{
		{0, 1, 0, 1, 0, 0},
		{1, 0, 1, 1, 0, 0},
		{0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 1, 0},
		{0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 1, 0}
	};
}

// BFS의 시간복잡도는 DFS와 동일
void Bfs(int here) // 가장 먼저 발견한 것을 먼저 방문, 선입선출과 비슷
{
	// ex) 누구에 의해서 발견되었는지?
	vector<int> parent(6, -1);
	// ex) 시작점에서 얼만큼 떨어져 있는지?
	vector<int> dist(6, -1);


	queue<int> q;
	// 예약 시스템 : 데이터 한 번 넣음
	q.push(here);
	discovered[here] = true;
	// 시작점으로 초기화
	parent[here] = here;
	dist[here] = 0;

	while (q.empty() == false) // 스캔이 다 끝날 때까지
	{
		// 큐가 비워질 때까지 데이터 꺼냄
		here = q.front();
		q.pop();

		// 방문 도장 찍기
		cout << "Visited : " << here << endl;

		// 인접한 정점 탐색
		// 인접 리스트 버전
		/*int size = adjacent[here].size();
		for (int i = 0; i < size; i++)
		{
			int there = adjacent[here][i];
			if (discovered[here]) // 이미 다른 경로에서 발견했다면 무시
				continue;

			// 방문 예약 (큐의 특징)
			q.push(there);
			discovered[there] = true;
		} */
		// 인접 행렬 버전
		for (int there = 0; there < 6; there++)
		{
			if (adjacent[here][there] == 0) // 주위 정점이 없다면 무시
				continue;
			if (discovered[there]) // 이미 다른 경로에서 발견했다면 무시
				continue;
			
			// 방문 예약
			q.push(there);
			discovered[there] = true;
			//
			parent[there] = here;
			dist[there] = dist[here] + 1; // 이전 좌표에서 1을 더함
		}
	}
}

void BfsAll()
{
	discovered = vector<bool>(6, false);

	for (int i = 0; i < 6; i++)
		if (discovered[i] == false)
			Bfs(i);
}

int main()
{
	CreateGraph();

	discovered = vector<bool>(6, false);
	Bfs(0);

	//BfsAll();
	return 0;
}