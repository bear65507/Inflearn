#include "pch.h"
#include "Player.h"
#include "Board.h"

void Player::Init(Board* board)
{
	_pos = board->GetEnterPos(); // 시작위치 설정
	_board = board; // 맵의 정보 저장

	//CalculatePath_RightHand(); // 길찾기
	CalculatePath_BFS();
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

void Player::CalculatePath_RightHand()
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

void Player::CalculatePath_BFS()
{
	Pos pos = _pos;
	Pos dest = _board->GetExitPos(); // 목적지

	Pos front[4] =
	{
		Pos(-1, 0),	// UP
		Pos(0, -1),	// LEFT
		Pos(1, 0),	// DOWN
		Pos(0, 1)	// RIGHT
	};

	const int32 size = _board->GetSize();
	vector<vector<bool>> discovered(size, vector<bool>(size, false)); // 2차원 배열 생성

	// discovered[y][x] ?
	// [ ][ ][ ][ ][ ]
	// [ ][ ][ ][ ][ ]

	// 추가 정보
	// parent[y][x] = pos --> (y,x)는 pos에 의헤 발견됨
	vector<vector<Pos>> parent(size, vector<Pos>(size, Pos(-1, -1)));

	// 예약 시스템 가동
	queue<Pos> q;
	q.push(pos);
	discovered[pos.x][pos.y] = true;
	parent[pos.y][pos.x] = pos; // 시작점 설정

	while (q.empty() == false) // 큐가 비어있지 않으면 
	{
		// 하나씩 꺼내며 방문 도장 찍기
		pos = q.front();
		q.pop();

		// 목적지 도착 시
		if (pos == dest)
			break;

		// 인접한 애들 스캔
		for (int32 dir = 0; dir < DIR_COUNT; dir++)
		{
			Pos nextPos = pos + front[dir];
			// 갈 수 있는 지역이 맞는지 확인
			if (CanGo(nextPos) == false)
				continue;
			// 이미 다른 경로에 의해 발견한 지역인지 확인
			if (discovered[nextPos.y][nextPos.x])
				continue; // 이중 체크 방지
			
			// 방문 안한 곳 예약 등록
			q.push(nextPos);
			discovered[nextPos.y][nextPos.x] = true;
			parent[nextPos.y][nextPos.x] = pos;
		}
	}

	_path.clear(); // 배열 초기화
	pos = dest;

	while (true)
	{
		_path.push_back(pos); // 현재 위치 기록

		// 시작점일 경우
		if (pos == parent[pos.y][pos.x])
			break;

		pos = parent[pos.y][pos.x]; // 뒤로 가는 효과
	}

	// 역순으로 가는 걸 뒤집기 == 시작점 -> 도착점
	vector<Pos> temp(_path.size());
	for (int i = 0; i < _path.size(); i++) 
		temp[i] = _path[_path.size() - 1 - i]; // 뒤부터 시작하고(-1), 한 칸 씩 뒤로 감(-i)
	
	_path = temp; // 옮겨 주기

	// std::reverse(_path.begin(), _path.end()); // STL 사용 (위 코드와 같음)
}
