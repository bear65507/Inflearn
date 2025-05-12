#include <iostream>
#include <string>
using namespace std;


int main()
{
	// 1) ASCII 코드 -> 영어만 고려
	// 문자 표현 7bit (0~127)
	char ch = 'A';

	// 2) ANSI
	// ASCII + 각국 언어별로 바이트를 늘려 표현
	// 127번까지는 ASCII, 그 이후부터는 새로운 페이지를 정함
	// ex) CP949, EUC-KR
	// 로케일 환경에 따라 문자가 깨질 수도 있음 (동일한 키코드 != 동일한 문자)
	
	setlocale(LC_ALL, "");
	cout << "LC_ALL: " << setlocale(LC_ALL, NULL) << endl;

	// 3) 유니코드
	// 동일 번호 = 동일한 문자 = 동일한 유니코드
	// 인코딩 방식 (대표적으로 UTF-8, UTF-16)
	// - UTF8 : 영어(1바이트), 한국어/중국어...(3바이트)'
	// - UTF16 : 영어(2), 한국어(2), 중국어(2) ...

	// 4) MBCS(Multi Byte Character Set) vs WBCS(Wide Byte Character Set)
	// - 멀티바이트 집합(MBCS) : 가변 길이 인코딩 (CP949, UTF-8)
	// - 유니코드 집합(WBCS) : 고정길이 인코딩 (UTF-16)

	// CP949 방식
	const char* test = "아아아"; // const char*에서 다른 언어가 섞여있으면 2바이트로 동작
	cout << test << endl;

	// UTF-8
	auto test2 = u8"가나다라마바사";
	setlocale(LC_ALL, "en_US.UTF-8");
	cout << test2 << endl;

	// UFT-16
	auto test3 = L"아야어요우유으이";
	wcout << test3 << endl;

	// char, string 말고 다른 버전의 문자열 (w = WBCS)
	wchar_t ch1 = L'루'; // L로 와이드 바이트라는 걸 표현
	wstring name = L"루이지";
	wcout << name << endl;

	return 0;
}