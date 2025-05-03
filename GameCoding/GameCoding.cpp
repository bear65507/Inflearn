#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 다익스트라 = BFS + 가중치(작을수록 우선순위 높다)
// 예약 시스템에서 등록한 모든 애들 중에서 점수가 가장 좋은 애 먼저 꺼냄
// 다익스트라 = 우선순위 큐

struct Vertex
{
	// int data;
};

vector<Vertex> vertices;
vector<vector<int>> adjacent;

void CreateGraph()
{
	vertices.resize(6);
	adjacent = vector<vector<int>>(6, vector<int>(6, -1));
	adjacent[0][1] = adjacent[1][0] = 15;
	adjacent[0][3] = adjacent[3][0] = 35;
	adjacent[1][2] = adjacent[2][1] = 5;
	adjacent[1][3] = adjacent[3][1] = 10;
	adjacent[3][4] = adjacent[4][3] = 5;
	adjacent[5][4] = adjacent[4][5] = 5;
}

struct VertexCost
{
	VertexCost(int cost, int vertex) : cost(cost), vertex(vertex) { }

	bool operator<(const VertexCost& other) const
	{
		return cost < other.cost;
	}
	bool operator>(const VertexCost& other) const
	{
		return cost > other.cost;
	}

	int cost;
	int vertex;
};

void Dijikstra(int here)
{
	priority_queue<VertexCost, vector<VertexCost>, greater<VertexCost>> pq;
	vector<int> best(6, INT32_MAX);
	vector<int> parent(6, -1);

	pq.push(VertexCost(0, here));
	best[here] = 0;
	parent[here] = here;

	while (pq.empty() == false)
	{
		// 제일 좋은 후보를 찾는다
		VertexCost v = pq.top();
		pq.pop();

		int cost = v.cost;
		here = v.vertex;

		// 더 짧은 경로를 뒤늦게 찾았다면 스킵
		if (best[here] < cost)
			continue;

		// 방문
		cout << "방문!" << here << endl;

		// 인접 행렬 방식
		for (int there = 0; there < 6; there++)
		{
			// 연결되지 않았다면 스킵
			if (adjacent[here][there] == -1)
				continue;

			// 지금까지 가려는 제일 좋은 비용 + 추가적으로 가야될 비용 
			int nextCost = best[here] + adjacent[here][there]; 
			// 더 좋은 경로를 과거에 찾았으면 스킵
			if (nextCost >= best[there])
				continue;

			// 지금까지 찾은 경로중에서는 최선의 수치 = 갱신
			best[there] = nextCost;
			parent[there] = here; // 나중에 갱신될 수 있음
			pq.push(VertexCost(nextCost, there));
				
		}
	}

}

int main()
{
	CreateGraph();

	Dijikstra(0);

	return 0;
}