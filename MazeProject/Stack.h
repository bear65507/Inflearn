#pragma once
#include "Vector.h"

template<typename T>
class Stack
{
public:
	void push(const T& value)
	{
		_container.push_back(value);
	}
	void pop()
	{
		_container.pop_back();
	}
	T& top() // 꺼내야 할 데이터(맨 마지막)
	{
		return _container.back();
	}

	int size() { return _container.size(); }
	bool empty() { return size() > 0; }
private:
	Vector<T> _container;
};

