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

	board.Init(25, &player);
	player.Init(&board);

	uint64 lastTick = 0; // 시간 관리(틱)
	while (true) 
	{
#pragma region 프레임관리 // 코드 접을 수 있음
		const uint64 currentTick = ::GetTickCount64(); // 시간 재기
		const uint64 deltaTick = currentTick - lastTick; // 지난 프레임의 틱까지 얼마나 경과가 되었느냐
		lastTick = currentTick;
#pragma endregion 

		// 입력


		// 로직 - 인공지능 길찾기
		player.Update(deltaTick); // 메 프레임마다 업데이트되는 함수

		// 렌더링 - 맵 생성
		board.Render();
	}

	return 0;
}

