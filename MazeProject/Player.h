#pragma once
#include "Vector.h"

class Board; // 전방선언

class Player
{
	enum
	{
		MOVE_TICK = 100 // 0.1초
	};
public:
	void		Init(Board* board);
	void		Update(uint64 deltaTick);

	void		SetPos(Pos pos) { _pos = pos; } // 위치 설정
	Pos		GetPos() { return _pos; } // 현재 위치 리턴 

	bool		CanGo(Pos pos); // 앞으로 갈 수 있는지

private:
	void CalculatePath();

private:
	Pos		_pos;
	int32	_dir = DIR_UP; // 플레이어가 현재 어디를 바라보고 있는지
	Board*	_board = nullptr;

	// 동적 배열
	Vector<Pos>	_path;  
	int32		_pathIndex; // 베열의 인덱스
	uint64		_sumTick = 0;
};

