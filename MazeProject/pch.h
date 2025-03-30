// 프리 컴파일 헤더(pre-complied header) : 컴파일 시간 단축, 헤더 재사용

// 프로젝트 속성 -> C/C++ -> (미리 컴파일 된 헤더 -> 사용) -> (미리 컴파일 된 헤더 파일 -> pch.h)
// pch.cpp 속성 -> (미리 컴파일 된 헤더 -> 만들기)
// pch 생성 전 cpp 파일에 pch.h include하기
#pragma once

// 사용할 헤더를 여기에 작성
#include "Types.h"
#include <Windows.h>
#include <iostream>

using namespace std;

struct Pos
{
	Pos() { }
	Pos(int32 y, int32 x) : y(y), x(x) { }

	bool operator==(const Pos& other) // 좌표가 같은지
	{
		return y == other.y and x == other.x;
	}

	bool operator!=(const Pos& other) // 좌표가 다른지
	{
		return !(*this == other); // 주소를 타고 가서 본인 좌표를 얻어와 other와 비교
	}

	Pos operator+(const Pos& other)
	{
		Pos ret;
		ret.y = y + other.y;
		ret.x = x + other.x;
		return ret;
	}

	Pos& operator+=(const Pos& other)
	{
		y += other.y;
		x += other.x;
		return *this;
	}

	int32 y = 0;
	int32 x = 0;
};

enum Dir // 방향
{
	DIR_UP = 0,
	DIR_LEFT = 1,
	DIR_DOWN = 2,
	DIR_RIGHT = 3,

	DIR_COUNT = 4 // 총 방향 갯수
};