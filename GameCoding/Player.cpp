#include "Player.h"
#include "Map.h"
#include "Helper.h"

int GPlayerX = 2;
int GPlayerY = 2;
bool canMove = true;

void MovePlayer(int x, int y)
{
	// 범위 체크
	if (x < 0 or x >= MAP_SIZE)
		return;
	if (y < 0 or y >= MAP_SIZE)
		return;
	// 벽 체크
	int index = y * MAP_SIZE + x;
	if (GMap1D[index] == 1)
		return;
	if (GMap2D[y][x] == 1)
	{
		return;
	}

	//기존 위치 정리
	{
		int prevIndex = GPlayerY * MAP_SIZE + GPlayerX;
		GMap1D[prevIndex] = 0;
		GMap2D[GPlayerY][GPlayerX] = 0;
	}

	// 새 위치 이동
	{
		GPlayerX = x;
		GPlayerY = y;
		int index = GPlayerY * MAP_SIZE + GPlayerX;
		GMap1D[index] = 2;
		GMap2D[GPlayerY][GPlayerX] = 2;
	}
}

void HandleMove()
{
	if (GMoveDir == MD_NONE)
	{
		canMove = true;
		return;
	}

	if (canMove == false)
		return;

	canMove = false;

	switch (GMoveDir)
	{
	case MD_LEFT:
		MovePlayer(GPlayerX - 1, GPlayerY);
		break;
	case MD_RIGHT:
		MovePlayer(GPlayerX + 1, GPlayerY);
		break;
	case MD_UP:
		MovePlayer(GPlayerX, GPlayerY - 1);
		break;
	case MD_DOWN:
		MovePlayer(GPlayerX, GPlayerY + 1);
		break;
	}
}