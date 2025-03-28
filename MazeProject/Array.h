#pragma once
#include <assert.h>

class Array
{
	using T = int;

public: // capacity�� �ѷ� �Ҵ�, push_back���� ������ �о�ֱ�, operator�� ������ ����
	explicit Array(int capacity = 100) : _capacity(capacity) // explicit : �ܺ��Լ����� ȣ��� ����Ǵ� ���� ����
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

	T& operator[](int index) // ���ȣ�� ����ϱ� ����
	{
		assert(index >= 0 and index < _size); // ������ �������� ������ ũ���� ��
		return _buffer[index];
	}

	int size() { return _size; }
	int capacity() { return _capacity; }

private:
	T* _buffer = nullptr;
	int _size = 0; // ���� �迭�� ũ��
	int _capacity = 0; // �Ҵ��� ��ü�� ũ��
};

