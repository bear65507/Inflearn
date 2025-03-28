#pragma once
#include <assert.h>

class Vector // 동적배열
{
	using T = int;

public: 
	explicit Vector() // explicit : 외부함수에서 호출시 통과되는 것을 방지
	{

	}

	~Vector()
	{
		if (_buffer)
			delete[] _buffer;
	}

	void clear() // 데이터 날림
	{
		if (_buffer)
		{
			delete[] _buffer;
			_buffer = new T[_capacity];
		}

		_size = 0; // 캐퍼시티는 변하지 않음
	}

	void push_back(const T& data) // 중요
	{
		if (_size == _capacity) // 사이즈가 꽉 찼을 때
		{
			// 증설 작업
			int newCapacity = static_cast<int>(_capacity * 1.5);
			if (newCapacity == _capacity)
				newCapacity++;

			reserve(newCapacity);
		}

		// 데이터 저장
		_buffer[_size] = data;

		// 데이터 개수 증가
		_size++;
	}

	void pop_back() // 데이터 꺼내오고 삭제
	{
		_size--;
	}

	T& back() // 맨 뒤 데이터
	{
		return _buffer[_size - 1];
	}

	void reserve(int capacity) // 캐퍼시티 증설
	{
		if (_capacity >= capacity)
			return;
		
		_capacity = capacity;

		T* newData = new T[_capacity];

		for (int i = 0; i < _size; i++) // 원래 있던 데이터 복사
			newData[i] = _buffer[i]; 

		if (_buffer)
			delete[] _buffer; // 원래 버퍼 삭제 후 교체

		_buffer = newData;
	}

	T& operator[](int index) 
	{
		assert(index >= 0 and index < _size); 
		return _buffer[index];
	}

	int size() { return _size; }
	int capacity() { return _capacity; }

private:
	T* _buffer = nullptr;
	int _size = 0; // 현재 배열의 크기
	int _capacity = 0; // 할당한 전체의 크기
};

