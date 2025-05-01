#include <iostream>
#include <vector>
using namespace std;

// DFS (Depth First Search) == 시작점으로 기준으로 얼마나 깊이 들어가는가
// DFS = 재귀함수, 트리와 다르게 양방향으로 이동할 수 있음을 고려 = 또는 스택으로 구현
// 

struct Vertex
{
	// int data;
};

vector<Vertex> vertices;
vector<vector<int>> adjacent;

// 내가 방문한 목록
vector<bool> visited;

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

void Dfs(int here) // here == 시작점
{
	// 방문 도장 찍기
	visited[here] = true;
	cout << "Visited : " << here << endl;

	/* 인접한 길을 다 체크해서 <인접 리스트 버전> 
	* 시간복잡도는 O(V+E) [V는 정점, E는 간선 개수]
	* (정점마다 한번씩 호출 V) + (간선의 총 개수 E개)) == V+E
	const int size = adjacent[here].size();
	for (int i = 0; i < size; i++)
	{
		int there = adjacent[here][i];
		if (visited[there] == false) // 방문하지 않은 곳만 DFS
			Dfs(there); 
	}
	*/

	// <인접 행렬 버전> 알고리즘은 같으나 표현 방법만 달라짐
	// 정점 개수가 V일 때, 시간복잡도는 O(V**2)
	// (정점마다 V번 Dfs()함수 호출) * (for문을 V번 만큼 순회) == V**2
	for (int there = 0; there < 6; there++)
	{
		// 길은 있는지
		if (adjacent[here][there] == 0)
			continue;

		// 아직 방문하지 않은 곳에 한해서 방문
		if (visited[there] == false)
			Dfs(there);
	}
}

void DfsAll() // 모든 정점들을 다 순회
{
	visited = vector<bool>(6, false);

	for (int i = 0; i < 6; i++)
		if (visited[i] == false)
			Dfs(i);
}

int main()
{
	CreateGraph();
	
	//visited = vector<bool>(6, false);
	//Dfs(0);

	DfsAll();

	return 0;
}