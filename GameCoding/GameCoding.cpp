#include <iostream>
#include <vector>
using namespace std;

class Iterator
{
public:
	Iterator() : _data(nullptr) { }
	Iterator(int* data) : _data(data) { }

	bool operator==(const Iterator& other)
	{
		return _data == other._data;
	}
	bool operator!=(const Iterator& other)
	{
		return _data != other._data;
	}

	void operator++()
	{
		_data++;
	}
	int& operator*()
	{
		return *_data;
	}
public:
	int* _data;
};

class Inventory
{
public:
	using iterator = Iterator;
	iterator begin() { return iterator(&_items[0]); }
	iterator end() { return iterator(&_items[10]); }

	int _items[10] = { 1,2,3,4,5,6,7,8,9,10 };
};

int main()
{
	// range-based for (☆ 알고 있다면 큰 도움이 됨)
	// 데이터를 수정하는 것은 되지만, 삽입 삭제는 불가능

	vector<int> v{ 1, 2, 3, 4, 5 };

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << endl;
	}

	for (auto it = v.begin(); it != v.end(); it++)
	{
		cout << *it << endl;
	}

	// ranged-based for, C#에서는 for-each
	for (int data : v)
	{
		cout << data << endl;
	}

	// 데이터를 바꾸고 싶을 때
	for (auto&/*int를 auto로 대체*/ data : v)
	{
		data = 100;
	}

	Inventory inventory;
	// items의 원소를 순회하는 코드
	for (auto& item : inventory) // 내부적으로는 순회자를 사용한것과 같다
	{
		cout << item << endl;
	}

	return 0;
}