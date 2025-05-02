#pragma once
#include "ConsoleHelper.h" // 작은 크기의 헤더는 추가해도 괜찮

enum
{
	BOARD_MAX_SIZE = 100 // 상수 생성 방법 중 하나 const, #define..
};

enum class TileType
{
	NONE = 0,
	EMPTY,
	WALL
};

class Player; // 전방선언 - 헤더끼리는 어지간해선 추가 X

class Board
{
public:
	Board();
	~Board();

	void Init(int32 size, class Player* player); // 초기화 - 로직실행
	void Render(); // 맵을 그려줌

	void GenerateMap(); // 맵 생성 로직
	TileType GetTileType(Pos pos);
	ConsoleColor GetTileColor(Pos pos);

	Pos GetEnterPos() { return Pos{ 1, 1 }; }
	Pos GetExitPos() { return Pos{ _size - 2, _size - 2 }; }
	int32 GetSize() { return _size; }

private:
	TileType		_tile[BOARD_MAX_SIZE][BOARD_MAX_SIZE]; // 최대 맵 크기
	int32		_size = 0; // 실제로 사용할 맵 크기
	Player*		_player = nullptr;
};

	