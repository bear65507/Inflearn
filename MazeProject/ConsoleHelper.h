#pragma once
#include "Types.h"


// enum class : 이름 범위 문제 해결, enum타입이 int로 간주되는 걸 막음
enum class ConsoleColor // 색상 팔레트
{
	BLACK = 0,
	RED = FOREGROUND_RED,
	GREEN = FOREGROUND_GREEN,
	BLUE = FOREGROUND_BLUE,
	YELLOW = RED | GREEN,
	WHITE = RED | GREEN | BLUE
};


class ConsoleHelper
{
public:
	static void SetCursorPosition(int32 x, int32 y); // static으로 ConsoleHelper 객체없이 호출
	static void SetCursorColor(ConsoleColor color);
	static void ShowConsoleCursor(bool flag);
};

