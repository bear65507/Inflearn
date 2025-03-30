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

class Board
{
public:
	Board();
	~Board();

	void Init(int32 size); // 초기화
	void Render();

	void GenerateMap(); 
	TileType GetTileType(Pos pos);
	ConsoleColor GetTileColor(Pos pos);

	Pos GetEnterPos() { return Pos{ 1, 1 }; }
	Pos GetExitPos() { return Pos{ _size - 2, _size - 2 }; }

private:
	TileType		_tile[BOARD_MAX_SIZE][BOARD_MAX_SIZE]; // 최대 맵 크기
	int32		_size = 0; // 실제로 사용할 맵 크기
};

	