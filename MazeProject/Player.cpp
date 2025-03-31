#include "pch.h"
#include "Player.h"
#include "Board.h"

void Player::Init(Board* board)
{
	_pos = board->GetEnterPos(); // 시작위치 설정
	_board = board; // 맵의 정보 저장

	CalculatePath(); // 길찾기
}

void Player::Update(uint64 deltaTick)
{
	if (_pathIndex >= _path.size())
		return;

	_sumTick += deltaTick;

	if (_sumTick >= MOVE_TICK) // 경과 틱이 0.1초 이상일때
	{
		_sumTick = 0;

		// 이동
		_pos = _path[_pathIndex]; // 위치값이 들어있는 배열에서 현재 위치 설정 
		_pathIndex++; // 다음 위치로 넘어감
	}
}

bool Player::CanGo(Pos pos)
{
	TileType tileType = _board->GetTileType(pos);
	return tileType == TileType::EMPTY;
}

void Player::CalculatePath()
{
	Pos pos = _pos;

	_path.clear(); // 배열 초기화
	_path.push_back(pos); // 현재 위치 저장

	// 목적지
	Pos dest = _board->GetExitPos();

	_dir; // 내가 바라보는 방향
	pos; // 현재 좌표

	Pos front[4] =
	{
		Pos(-1, 0),	// UP
		Pos(0, -1),	// LEFT
		Pos(1, 0),	// DOWN
		Pos(0, 1)	// RIGHT
	};

	// 내가 바라보는 방향 기준 앞에 있는 좌표를 구함
	Pos next = pos + front[_dir];

	// 오른쪽 방향 90도 회전
	_dir = (_dir - 1) % DIR_COUNT;

	// 왼쪽 방향 90도 회전
	_dir = (_dir + 1) % DIR_COUNT;

	// 목적지를 찾을 때 까지
	while (pos != dest)
	{
		// 1. 현재 바라보는 방향을 기준으로, 오른쪽으로 갈 수 있는지 확인
		int32 newDir = (_dir - 1 + DIR_COUNT) % DIR_COUNT;
		if (CanGo(pos + front[newDir]))
		{
			// 오른쪽 방향으로 90도 회전
			_dir = newDir;
			// 앞으로 한보 전진
			pos = pos + front[_dir];
			// 좌표 기록
			_path.push_back(pos);
		}
		// 2. 현재 바라보는 방향을 기준으로 전진할 수 있는지 확인
		else if(CanGo(pos + front[_dir]))
		{
			// 앞으로 한 보 전진
			pos = pos + front[_dir];
			// 좌표 기록
			_path.push_back(pos);
		}
		else
		{
			// 왼쪽 방향으로 90도 회전
			_dir = (_dir + 1) % DIR_COUNT;
		}
	}

}
