#include <iostream>
using namespace std;

int main()
{
	cout << "삼각형의 크기를 입력하세요: ";
	int N;
	cin >> N;
	cout << "어떤 모양으로 삼각형을 만들까요?: ";
	char sym;
	cin >> sym;


	for (int i = 0; i < N; i++)
	{
		/* 좌측 삼각형 */
		for (int j = 0; j < N - i; j++)
		{
			cout << " ";
		}
		for (int k = 0; k <= i; k++)
		{
			cout << sym;
		}
		/* 우측 삼각형 */
		for (int s = 0; s <= i; s++)
		{
			cout << sym;
		}
		cout << endl;
	}

	return 0;
}