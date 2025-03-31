#include "pch.h"
#include "Board.h"
#include "Player.h"
const char* TILE = "■";

Board::Board()
{
}

Board::~Board()
{
}

void Board::Init(int32 size, Player* player) 
{
	_size = size;
	_player = player;
	GenerateMap();
}

void Board::Render()
{
	ConsoleHelper::SetCursorPosition(0, 0); // 0,0으로 커서 옮김
	ConsoleHelper::ShowConsoleCursor(false); // 커서 깜빡임 끄기

	for (int32 y = 0; y < 25; y++)
	{
		for (int32 x = 0; x < 25; x++)
		{
			ConsoleColor color = GetTileColor(Pos(y, x)); // 현재 커서 위 타일의 색상 정보 받아옴
			ConsoleHelper::SetCursorColor(color); // 색상 선택
			cout << TILE; // 타일 출력
		}

		cout << endl;
	}
}

// Binary Tree 미로 생성 알고리즘
void Board::GenerateMap()
{
	for (int32 y = 0; y < _size; y++)
	{
		for (int32 x = 0; x < _size; x++)
		{
			if (x % 2 == 0 or y % 2 == 0) // x, y 하나가 짝수면 그 타일은 벽
				_tile[y][x] = TileType::WALL;
			else
				_tile[y][x] = TileType::EMPTY;
		}
	}
	// 랜덤으로 우측 혹은 아래로 길을 뚫는 작업
	for (int32 y = 0; y < _size; y++)
	{
		for (int32 x = 0; x < _size; x++)
		{
			// 벽이면 스킵
			if (x % 2 == 0 or y % 2 == 0)
				continue;

			// 목표 지점
			if (y == _size - 2 and x == _size - 2)
				continue;

			// 하단 도달 : 우측으로
			if (y == _size - 2)
			{
				_tile[y][x + 1] = TileType::EMPTY; // 우측 좌표에 접근 후 empty로 뚫음 
				continue;
			}

			// 우측에 도달 : 하단으로 뚫기
			if (x == _size - 2)
			{
				_tile[y + 1][x] = TileType::EMPTY; // 아래 좌표에 접근 후 empty로 뚫음 
				continue;
			}

			const int32 randValue = ::rand() % 2;
			if (randValue == 0)
				_tile[y][x + 1] = TileType::EMPTY; // 오른쪽으로 이동
			else
				_tile[y + 1][x] = TileType::EMPTY; // 아래로 이동
		}
	}
}

TileType Board::GetTileType(Pos pos)
{
	if(pos.x < 0 or pos.x >= _size) // 예외처리, 갈 수 없는 타일일 때
		return TileType::NONE;
	if (pos.y < 0 or pos.y >= _size)
		return TileType::NONE;

	return _tile[pos.y][pos.x];
}

ConsoleColor Board::GetTileColor(Pos pos) // 타일 색깔 칠하기
{
	if (_player and _player->GetPos() == pos) // 플레이어가 존재하고 현재 위치가 pos일때
		return ConsoleColor::YELLOW;
	if (GetExitPos() == pos)
		return ConsoleColor::BLUE;

	TileType tileType = GetTileType(pos);

	switch (tileType)
	{
	case TileType::EMPTY:
		return ConsoleColor::GREEN; // return할거면 break 안해도 됨
	case TileType::WALL:
		return ConsoleColor::RED;
	}

	return ConsoleColor::WHITE;
}
