#pragma once
#include <assert.h>

class Array
{
	using T = int;

public: // capacity로 총량 할당, push_back으로 데이터 밀어넣기, operator로 데이터 접근
	explicit Array(int capacity = 100) : _capacity(capacity) // explicit : 외부함수에서 호출시 통과되는 것을 방지
	{
		_buffer = new T[capacity];
	}

	~Array()
	{
		delete[] _buffer;
	}

	void push_back(const T& data)
	{
		if (_size == _capacity)
			return;

		_buffer[_size] = data;
		_size++;
	}

	T& operator[](int index) // 대괄호를 사용하기 위함
	{
		assert(index >= 0 and index < _size); // 조건을 만족하지 않으면 크래시 냄
		return _buffer[index];
	}

	int size() { return _size; }
	int capacity() { return _capacity; }

private:
	T* _buffer = nullptr;
	int _size = 0; // 현재 배열의 크기
	int _capacity = 0; // 할당한 전체의 크기
};

