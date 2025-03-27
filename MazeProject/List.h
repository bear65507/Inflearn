#pragma once
#include <iostream>
using namespace std;

class Node
{
	//typedef int T; // ��Ī ��� (T = int)
	using T = int; // typedef�� ���� ����
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
		_head = new Node(0); // ���� ��� ����
		_tail = new Node(0);
		_head->next = _tail;
		_tail->prev = _head;
	}

	~List()
	{
		Node* node = _head;
		while (node != nullptr) // ���� ����
		{
			Node* deleteNode = node;

			//Node* nextNode = node->next;
			//node = nextNode; // �� �ڵ�� ����
			node = node->next; // ��带 �Űܴٴϴ� Ŀ�� ����
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
			if (node == _tail->prev) // ���� �������� ��
				return nullptr;

			node = node->next;
		}

		return node;
	}

	void Print()
	{
		Node* node = _head->next; // _head = �����̹Ƿ� �ѱ�
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

// (��)���Ḯ��Ʈ���� Ư�� ��� ��ġ�� �˰� �������� ��� ����/������ ������

//					[node]
// [dummy]<->[prevNode]<->[posNode]<->[3]<->[dummy]
// [head]								[tail]
	void Insert(Node* posNode, int data)
	{
		Node* node = new Node(data);
		Node* prevNode = posNode->prev;

		prevNode->next = node; // prevNode�� posNode ���̿� ��� �߰�
		node->prev = prevNode;
		node->next = posNode;
		posNode->prev = node;
	}

// [dummy]<->[prevNode]<->[node]<->[nextNode]<->[3]<->[dummy]
// [head]										[tail]
	Node* Remove(Node* node)
	{
		Node* prevNode = node->prev;
		Node* nextNode = node->next; // prevNode �� nextNode ������ ��� ���� (�о���)
		prevNode->next = nextNode;
		nextNode->prev = prevNode;

		delete node;

		return nextNode;
	}

private:
	Node* _head = nullptr;
	Node* _tail = nullptr;
};

