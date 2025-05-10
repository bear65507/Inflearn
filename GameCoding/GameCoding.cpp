#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
	find()
	find_if()
	count_if()
	all_of()
	any_of()
	none_of()
	for_each()
	remove_if()
*/
int main()
{
	vector<int> v;

	for (int i = 0; i < 100; i++)
	{
		int n = rand() % 100;
		v.push_back(n);
	}

	// Q1) 특정 숫자가 있는지? => std::find()
	{
		// 기존에 쓰던 방법
		int number = 50;

		vector<int>::iterator it;
		for (it = v.begin(); it != v.end(); it++)
		{
			int value = *it;
			if (value == number)
			{
				break;
			}
		}
		if (it != v.end())
		{
			// TODO
		}

		// algorithm의 find() 이용
		auto it = std::find(v.begin(), v.end(), number);
		if (it == v.end())
			cout << "못찾음" << endl;
		else
			cout << "찾음" << endl;
	}

	// Q2) 11로 나뉘는 숫자가 있는지? => std::find_if()
	{
		// 기존 방법
		int div = 11;
		vector<int>::iterator it;
		for (it = v.begin(); it != v.end(); it++)
		{
			int value = *it;
			if (value % div == 0)
			{
				break;
			}
		}

		/* -------------------------- */
		struct CanDivideBy11 // 함수자(함수처럼 동작함)
		{
			bool operator()(int n)
			{
				return n % 11 == 0;
			}
		};
		// find_if(), 3번째 인자는 predicate, 판별식이 들어감
		auto it = std::find_if(v.begin(), v.end(), CanDivideBy11()); 
		if (it == v.end())
			cout << "못찾음" << endl;
		else
			cout << "찾음" << endl;
	}

	// Q3) 홀수인 숫자 개수는 몇개? => std::count_if()
	{
		// 기존 방식
		int count = 0;
		for (auto it = v.begin(); it != v.end(); it++)
		{
			if (*it % 2 != 0)
				count++;
		}

		/* ------------------------- */
		struct IsOdd
		{
			bool operator()(int n)
			{
				return n % 2 != 0;
			}
		};
		// count_if(), 마찬가지로 3번째 인자에는 판별식
		int n = std::count_if(v.begin(), v.end(), IsOdd());

		// 모든 데이터가 홀수인가?
		bool b1 = std::all_of(v.begin(), v.end(), IsOdd());
		// 홀수인 데이터가 하나라도 있는가?
		bool b2 = std::any_of(v.begin(), v.end(), IsOdd());
		// 모든 데이터가 홀수가 아닌가?
		bool b3 = std::none_of(v.begin(), v.end(), IsOdd());
	}

	// Q4) 벡터에 있는 모든 숫자들에게 3을 곱해달라 => std::for_each()
	{
		// 기존 방식
		for (int i = 0; i < v.size(); i++)
			v[i] *= 3;

		/* ------------------------------- */
		struct MultiplyBy3
		{
			void operator()(int& n)
			{
				n *= 3;
			}
		};
		std::for_each(v.begin(), v.end(), MultiplyBy3());
	}

	// Q5) 홀수인 데이터를 일괄 삭제 => [std::remove_it(), erase](☆)
	{
		// 기존 방식
		for (auto it = v.begin(); it != v.end(); it)
		{
			if (*it % 2 != 0)
				it = v.erase(it);
			else
				it++;
		}

		/* ---------------------------- */
		struct IsOdd
		{
			bool operator()(int n)
			{
				return n % 2 != 0;
			}
		};
		// remove_if를 사용할 때 주의할점 : 
		// 삭제할 원소는 날리고, 아닌 원소는 남기는데 같은 벡터에다 작업함
		// 1 4 3 5 8 2 --> 4 8 2 5 8 2 == 뒷부분 5 8 2를 남김
		auto it = std::remove_if(v.begin(), v.end(), IsOdd());
		v.erase(it, v.end()); // remove_if와 erase는 세트로 생각
	}

	return 0;
}