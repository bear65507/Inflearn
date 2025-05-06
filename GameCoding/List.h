#pragma once
#include <iostream>
using namespace std;

template<typename T>
class Node
{
	//typedef int T; // 별칭 사용 (T = int)
	//using T = int; // typedef의 요즘 문법
public:
	Node(int data) : data(data), prev(nullptr), next(nullptr) {}
public:
	T data;
	Node* prev;
	Node* next;
};

template<typename T>
class Iterator
{
public:
	Iterator() : _node(nullptr) { }
	Iterator(Node<T>* node) : _node(node) { }

	// ++it
	Iterator& operator++()
	{
		_node = _node->next; // 다음 노드로 넘어간다
		return *this;
	}

	Iterator operator++(int)
	{
		Iterator temp = *this;
		_node = _node->next;
		return temp;
	}

	// *it
	T& operator*()
	{
		return _node->data;
	}

	bool operator==(const Iterator& other)
	{
		return _node == other._node;
	}
	bool operator!=(const Iterator& other)
	{
		return _node != other._node;
	}

public:
	Node<T>* _node;
};

template<typename T>
class List
{
public:
	using iterator = Iterator<T>;

	// 제일 앞에는 더미노드가 있으므로 실제 데이터는 head 다음에 있음
	iterator begin() { return iterator(_head->next); } 
	iterator end() { return iterator(_tail); } // tail이 더미노드니 end()의 위치로 적합

	List()
	{
		_head = new Node<T>(0); // 더미 노드 생성
		_tail = new Node<T>(0);
		_head->next = _tail;
		_tail->prev = _head;
	}

	~List()
	{
		Node<T>* node = _head;
		while (node != nullptr) // 노드들 삭제
		{
			Node<T>* deleteNode = node;

			//Node* nextNode = node->next;
			//node = nextNode; // 밑 코드와 동일
			node = node->next; // 노드를 옮겨다니는 커서 생성
			delete deleteNode;
		}
	}

	Node<T>* GetNode(int index)
	{
		Node<T>* node = _head->next;
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
		Node<T>* node = _head->next; // _head = 더미이므로 넘김
		while (node != _tail)
		{
			cout << node->data << " ";
			node = node->next;
		}
		cout << endl;
	}


	Node<T>* AddAtHead(int data)
	{
		Node<T>* node = new Node<T>(data);
		Node<T>* nextNode = _head->next;

		node->next = nextNode;
		nextNode->prev = node;
		_head->next = node;
		node->prev = _head;

		return node;
	}


	Node<T>* AddAtTail(int data)
	{
		Node<T>* node = new Node<T>(data);
		Node<T>* prevNode = _tail->prev;

		prevNode->next = node;
		node->prev = prevNode;
		node->next = _tail;
		_tail->prev = node;

		return node;
	}

	// (☆)연결리스트에서 특정 노드 위치를 알고 있을때만 노드 삽입/삭제가 빠르다


	void Insert(Node<T>* posNode, int data)
	{
		Node<T>* node = new Node<T>(data);
		Node<T>* prevNode = posNode->prev;

		prevNode->next = node; // prevNode와 posNode 사이에 노드 추가
		node->prev = prevNode;
		node->next = posNode;
		posNode->prev = node;
	}


	Node<T>* Remove(Node<T>* node)
	{
		Node<T>* prevNode = node->prev;
		Node<T>* nextNode = node->next; // prevNode 와 nextNode 사이의 노드 삭제 (밀어줌)
		prevNode->next = nextNode;
		nextNode->prev = prevNode;

		delete node;

		return nextNode;
	}

private:
	Node<T>* _head = nullptr;
	Node<T>* _tail = nullptr;
};

