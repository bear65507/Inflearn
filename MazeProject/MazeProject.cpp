// A* 알고리즘 사용 예정
#include "pch.h"
#include "Vector.h"
#include "Board.h"
#include "Player.h"

Board board;
Player player;

int main()
{
	::srand(static_cast<uint32>(time(nullptr))); // 랜덤함수 시드값 생성

	while (true) 
	{
		// 입력


		// 로직 - 인공지능 길찾기


		// 렌더링 - 맵 생성
		board.Render();
	}

	return 0;
}

