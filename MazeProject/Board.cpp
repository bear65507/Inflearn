#include "pch.h"
#include "Board.h"

const char* TILE = "■";

Board::Board()
{
}

Board::~Board()
{
}

void Board::Init(int32 size) 
{
	_size = size;
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

void Board::GenerateMap()
{
}

TileType Board::GetTileType(Pos pos)
{
	return TileType::NONE;
}

ConsoleColor Board::GetTileColor(Pos pos)
{
	return ConsoleColor::RED;
}
