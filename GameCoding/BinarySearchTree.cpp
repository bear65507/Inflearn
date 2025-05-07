#include "BinarySearchTree.h"
#include <iostream>
#include <Windows.h>
using namespace std;

void SetCursorPosition(int x, int y)
{
	HANDLE output = ::GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = { static_cast<SHORT>(x), static_cast<SHORT>(y) };
	::SetConsoleCursorPosition(output, pos);
}

void BinarySearchTree::Insert(int key)
{
	Node* newNode = new Node();
	newNode->key = key;

	if (_root == nullptr) // 빈 트리에 첫번째로 삽입할 때
	{
		_root = newNode;
		return;
	}

	// 추가할 위치를 찾기
	Node* node = _root;
	Node* parent = nullptr;

	while (node) // 리프노드까지 순회
	{
		parent = node;
		if (key < node->key) // 비교하는 노드보다 작을 때, 왼쪽으로 이동
			node = node->left;
		else
			node = node->right; // 오른쪽으로 이동
	}

	newNode->parent = parent;

	if (key < parent->key) // 부모노드보다 작으면, 왼쪽으로
		parent->left = newNode;
	else
		parent->right = newNode; // 크다면, 오른쪽으로
}

Node* BinarySearchTree::Search(Node* node, int key)
{
	// 트리 구조상 재귀함수가 편리
	if (node == nullptr or key == node->key) // 키값을 찾았을 때
		return node;

	if (key < node->key) // 키값이 노드보다 작을 때, 왼쪽으로 검색
		Search(node->left, key);
	else
		Search(node->right, key); 

}

Node* BinarySearchTree::Min(Node* node)
{
	if (node == nullptr)
		return nullptr;

	// 최소값 노드 찾기 : 리프 노드까지 왼쪽으로 이동
	while (node->left)
		node = node->left;

	return node;
}

Node* BinarySearchTree::Max(Node* node)
{
	if (node == nullptr)
		return nullptr;

	// 최소값 노드 찾기 : 리프 노드까지 오른쪽으로 이동
	while (node->right)
		node = node->right;

	return node;
}

Node* BinarySearchTree::Next(Node* node)
{
	// 삭제할 노드 다음으로 큰 값 찾기
	// 오른쪽 자식 노드로 갈 수 있으면 이동 후 왼쪽으로 쭉 이동
	// 오른쪽 자식 노드가 없다면 나를 왼쪽 자식으로 들고 있는 부모 노드 찾기

	if (node->right)
		return Min(node->right);

	Node* parent = node->parent;
	while (parent and node == parent->right) 
	{
		// 한 칸씩 올라가며 나를 왼쪽 자식으로 들고 있는 부모 노드 찾기
		node = parent;
		parent = parent->parent;
	}

	return nullptr;
}

void BinarySearchTree::Replace(Node* u, Node* v) // u를 v로 대체
{
	if (u->parent == nullptr) // 삭제될 노드가 루트 노드일때
		_root = v;
	else if (u == u->parent->left) // u의 부모노드가 조부모 노드의 왼쪽 자식일 때
		u->parent->left = v;
	else							// 오른쪽 자식일 때
		u->parent->right = v;

	if (v)
		v->parent = u->parent; // 부모노드에서도 연결
}

void BinarySearchTree::Delete(int key)
{
	Node* deleteNode = Search(_root, key); // 루트부터 키까지 탐색
	Delete(deleteNode);
}

void BinarySearchTree::Delete(Node* node)
{
	if (node == nullptr) // 예외 체크
		return;

	if (node->left == nullptr) // 오른쪽 자식만 가지고 있을 때
	{
		Replace(node, node->right); // 오른쪽 자식을 삭제할 노드 위치로 교체
	}
	else if (node->right == nullptr)
	{
		Replace(node, node->left);
	}
	else // 자식들이 양쪽 모두 있을 때
	{
		Node* next = Next(node);
		node->key = next->key; // 삭제할 노드 다음으로 큰 노드값을 복사
		Delete(next);
	}
}

void BinarySearchTree::Print(Node* node, int x, int y)
{
	if (node == nullptr) // 예외 체크
		return;

	SetCursorPosition(x, y);

	cout << node->key;

	Print(node->left, x - (5 / (y + 1)), y + 1);
	Print(node->right, x + (5 / (y + 1)), y + 1);
}
