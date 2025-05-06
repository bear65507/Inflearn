#include <iostream>
#include <vector>
using namespace std;

// auto

class Knight
{

};

template<typename T>
void Print(T msg)
{
	cout << msg << endl;
}

int main()
{
	// C++03 -> 지금 배우고 있는거
	// C++11 - (Modern C++), 대격변?
	// C++14
	// C++17
	// C++20 - 대격변2

	{
		int a = 3;
		float b = 3.14f;
		double c = 1.23;
		Knight* d = new Knight();
		const char* e = "Rookiss";
	}


	// auto
	// - 장점 : 각 타입마다 타이핑할 필요 없음, 특히 이터레이터
	// - 단점 : 가독성이 떨어짐
	//
	vector<int> v;
	auto it = v.begin();

	{
		auto a = 3;
		auto b = 3.14f;
		auto c = 1.23;
		auto d = new Knight();
		auto e = "Rookiss";

		// auto는 일종의 조커 카드
		// 템플릿과 작동 원리가 비슷 (컴파일 타임에 이루어짐)

		Print(1);
		Print("Rookiss");
		// 형식 연역 (type deduction)
		// -> 말이 되도록 추론

		int& ref = a;
		const int cst = a;

		// auto는 const, &는 때고 추론한다
		// 따라서 직접 붙여줘야함
		auto& ref2 = ref;
		const auto cst2 = cst;

	}


	return 0;
}