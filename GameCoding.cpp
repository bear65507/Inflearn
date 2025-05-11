#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// 거품 정렬 : O(N^2)
void BobbleSort(vector<int>& v)
{
	const int n = v.size();

	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (v[j] > v[j + 1])
			{
				int temp = v[j];
				v[j] = v[j + 1];
				v[j + 1] = temp;

				// swap(v[j], v[j + 1]);
			}
		}
	}
}

// 선택 정렬 : O(N^2)
void SelectionSort(vector<int>& v)
{
	const int n = v.size();
	for (int i = 0; i < n - 1; i++)
	{
		int bestidx = i;
		for (int j = i + 1; j < n; j++)
		{
			if (v[j] < v[bestidx])
				bestidx = j;
		}
		if (i != bestidx)
			swap(v[i], v[bestidx]);
	}
}

// 힙 정렬 : O(Nlog N)
void HeapSort(vector<int>& v)
{
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int num : v) // 벡터의 원소들을 우선순위 큐에 넣음 (정렬된 상태로 들어감)
		pq.push(num);

	v.clear();
	while (pq.empty() == false)
	{
		v.push_back(pq.top()); // 다시 벡터에 정렬된 원소들을 넣음
		pq.pop();
	}
}

// 병합정렬 : O(Nlog N)
// 분할 정복 (Divide and Conquer) 알고리즘
// - 분할(Divide)		: 문제를 더 단순하게 분할	: O(log N)
// - 정복(Conquer)	: 분할된 문제를 해결		: O(N)
// - 결합(Combine)	: 결과를 취합하여 마무리	: O(Nlog N)
void MergeResult(vector<int>& v, int left, int mid, int right)
{
	int leftidx = left;
	int rightidx = mid + 1;
	vector<int> temp;

	while (leftidx <= mid and rightidx <= right)
	{
		if (v[leftidx] <= v[rightidx]) // 왼쪽 벡터가 오른쪽보다 작으면
		{
			temp.push_back(v[leftidx]); // 왼쪽 먼저 새 벡터에 넣어줌
			leftidx++;
		}
		else
		{
			temp.push_back(v[rightidx]);
			rightidx++;
		}
	}

	if (leftidx > mid) // 왼쪽 벡터가 먼저 새 벡터에 다 들어갔을 때
	{
		while (rightidx <= right) // 오른쪽 벡터의 남은 원소들을 다 새 벡터에 넣음
		{
			temp.push_back(v[rightidx]);
			rightidx++;
		}
	}
	else
	{
		while (leftidx <= left) 
		{
			temp.push_back(v[leftidx]);
			leftidx++;
		}
	}

	for (int i = 0; i < temp.size(); i++)
	{
		v[left + i] = temp[i];
	}
}

void MergeSort(vector<int>& v, int left, int right)
{
	if (left >= right) // 분할된 벡터의 원소가 1개일 때
		return;

	int mid = (left + right) / 2;

	// 절반씩 나눔
	MergeSort(v, left, mid);
	MergeSort(v, mid + 1, right);

	MergeResult(v, left, mid, right);
}

// 퀵 정렬 : 평균적으로 O(Nlog N)
// 피벗을 잘못 잡으면 최악의 경우 O(N^2)
int Partition(vector<int>& v, int left, int right) // O(N)
{
	// 피벗을 정함
	int pivot = v[left];
	int low = left + 1;
	int high = right;

	while (low <= high) // low가 high보다 왼쪽에 있을 때
	{
		while (low <= right and pivot >= v[low])
		{
			// low의 값이 pivot보다 작을 때 low를 오른쪽으로 움직임
			low++; 
		}
		while (high >= left + 1 and pivot <= v[high])
		{
			// high의 값이 pivot보다 클 때 high를 왼쪽으로 움직임
			high--;
		}

		if (low < high)
			swap(v[low], v[high]); // low와 high가 멈추면, 둘의 위치를 바꿈
	}

	swap(v[left], v[high]); // 피벗과 high의 값을 바꾸고
	return high; // 피벗의 위치 반환
}

void QuickSort(vector<int>& v, int left, int right) // O(log N)
{
	if (left > right)
		return;

	int pivot = Partition(v, left, right); // 피벗 정하기

	// 피벗의 왼쪽 오른쪽을 기준으로 다시 퀵소트
	QuickSort(v, left, pivot - 1);
	QuickSort(v, pivot + 1, right);

}


int main()
{
	vector<int> v{ 1, 5, 3, 4, 2 };

	// std::sort(v.begin(), v.end()); // std::sort()
	//BobbleSort(v);
	//SelectionSort(v);
	//HeapSort(v);

	//MergeSort(v, 0, v.size() - 1);
	QuickSort(v, 0, v.size() - 1);
	return 0;
}