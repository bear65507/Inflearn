#pragma once

struct Node
{
	Node* parent = nullptr; // 부모노드
	Node* left = nullptr;
	Node* right = nullptr;
	int key = 0; // 데이터
};

class BinarySearchTree
{
public:
	void Print() { Print(_root, 10, 0); }
	void Print(Node* node, int x, int y); // 루트노드를 기준으로 x,y 좌표를 그려줌
		 
	void Insert(int key);
	Node* Search(Node* node, int key);

	// 삭제를 위한 헬퍼함수
	Node* Min(Node* node);
	Node* Max(Node* node);
	Node* Next(Node* node); // 삭제할 노드 다음으로 큰 노드를 찾는 함수
	void Replace(Node* u, Node* v); // 삭제한 노드의 부모노드와 자식노드를 연결

	void Delete(int key);
	void Delete(Node* node);

private:
	Node* _root = nullptr; // 루트노드
};

