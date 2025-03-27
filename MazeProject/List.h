#pragma once
#include <iostream>
using namespace std;

class Node
{
	//typedef int T; // 별칭 사용 (T = int)
	using T = int; // typedef의 요즘 문법
public:
	Node(int data) : data(data), prev(nullptr), next(nullptr) { }
public:
	int data;
	Node* prev;
	Node* next;
};

class List
{
public:
	List()
	{
		_head = new Node(0); // 더미 노드 생성
		_tail = new Node(0);
		_head->next = _tail;
		_tail->prev = _head;
	}

	~List()
	{
		Node* node = _head;
		while (node != nullptr) // 노드들 삭제
		{
			Node* deleteNode = node;

			//Node* nextNode = node->next;
			//node = nextNode; // 밑 코드와 동일
			node = node->next; // 노드를 옮겨다니는 커서 생성
			delete deleteNode;
		}
	}

	Node* GetNode(int index)
	{
		Node* node = _head->next;
		if (node == _tail)
			return nullptr;

		for (int i = 0; i < index; i++)
		{
			if (node == _tail->prev) // 끝에 도달했을 때
				return nullptr;

			node = node->next;
		}

		return node;
	}

	void Print()
	{
		Node* node = _head->next; // _head = 더미이므로 넘김
		while (node != _tail)
		{
			cout << node->data << " ";
			node = node->next;
		}
		cout << endl;
	}

	//		[node]
	// [dummy]<->[nextNode]    <-> [dummy]
	// [head]					[tail]
	Node* AddAtHead(int data) 
	{
		Node* node = new Node(data);
		Node* nextNode = _head->next;

		node->next = nextNode;
		nextNode->prev = node;
		_head->next = node;
		node->prev = _head;

		return node;
	}

	//							[node]
	// [dummy]<->			[prevNode]<->[dummy]
	// [head]						[tail]
	Node* AddAtTail(int data)
	{
		Node* node = new Node(data);
		Node* prevNode = _tail->prev;

		prevNode->next = node;
		node->prev = prevNode;
		node->next = _tail;
		_tail->prev = node;

		return node;
	}

// (☆)연결리스트에서 특정 노드 위치를 알고 있을때만 노드 삽입/삭제가 빠르다

//					[node]
// [dummy]<->[prevNode]<->[posNode]<->[3]<->[dummy]
// [head]								[tail]
	void Insert(Node* posNode, int data)
	{
		Node* node = new Node(data);
		Node* prevNode = posNode->prev;

		prevNode->next = node; // prevNode와 posNode 사이에 노드 추가
		node->prev = prevNode;
		node->next = posNode;
		posNode->prev = node;
	}

// [dummy]<->[prevNode]<->[node]<->[nextNode]<->[3]<->[dummy]
// [head]										[tail]
	Node* Remove(Node* node)
	{
		Node* prevNode = node->prev;
		Node* nextNode = node->next; // prevNode 와 nextNode 사이의 노드 삭제 (밀어줌)
		prevNode->next = nextNode;
		nextNode->prev = prevNode;

		delete node;

		return nextNode;
	}

private:
	Node* _head = nullptr;
	Node* _tail = nullptr;
};

