#include <iostream>
#include <string>
using namespace std;


int main()
{
	// C스타일 문자열
	// 문자열이 시작하는 위치를 포인터로 들고 있고, null문자로 끝임을 알림
	char name[] = "Rookiss";
	char name2[] = "Rookiss";

	if (name == name2) // 두 문자열의 주소값을 비교
	{
		cout << "같음" << endl; 
	}
	else
	{
		cout << "다름" << endl;
	}
	// 다루기가 불편 (strcmp, strcat...)

	// string 문자열
	std::string str = "Rookiss";
	std::string str2 = "Rookiss";

	// 1) 비교
	// ex) ID/PW 맞는지
	if (str == str2)
	{
		// TODO
	}

	// 2) 복사
	string str3;
	str3 = str; // 원본에는 영향을 주지 않음

	// 3) 추가
	str.append("1234");
	str += "1234";

	// 4) 찾기
	auto c = str.find("Roo"); // 몇번째 인덱스에 Roo가 있는지 찾음
	if (c == std::string::npos) // npos가 벡터의 end()와 같음
	{
		cout << "not found" << endl;
	}

	// 5) 교체
	string chatStr = "SHIT !!!";
	string findStr = "SHIT";
	string replaceStr = "****";

	chatStr.replace(chatStr.find(findStr), findStr.length(), replaceStr);

	string str4 = str.substr(0, 3); // 문자열 자르기

	return 0;
}