#pragma once
#include "Vector.h"

// [front/back][][][][][][][] // front/back은 데이터를 꺼내고 넣는 커서 같은 개념
// [][][front][back][][][][] (개념상으론 양 끝이 원형으로 연결되어있음)
template<typename T>
class Queue
{
public:
	Queue()
	{
		_container.resize(100);
	}

	void push(const T& value) // _back에다 데이터를 넣어주고 오른쪽으로 한칸 이동
	{
		if (_size == _container.size())
		{
			// TODO : 다 찼는지 체크
		}
		_container[_back] = value;
		_back = { _back + 1 } % _container.size(); // 맨 끝 범위를 벗어났어도 다시 앞으로 돌아옴
		_size++;
	}
	void pop() // 데이터를 꺼내오고 _front를 오른쪽으로 한 칸 밈
	{
		_front = { _front + 1 };
		_size--;
	}
	T& front() // 꺼내야 할 데이터(맨 앞)
	{
		return _container[_front];
	}
	bool empty() { return _size == 0; }
	int size() { return _size; }
private:
	Vector<T> _container;

	int _front = 0; 
	int _back = 0; 
	int _size = 0;
};

