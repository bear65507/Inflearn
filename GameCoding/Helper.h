 #pragma once // include를 여러번 해도 한번만 추가되게 함 (헤더 가드)
			
//void Test(int);
//void Test2();
//#define TEST 3
//enum PlayerType
//{
//	Knight,
//	Mage
//};
//extern int Gtest; // =이 변수가 외부에 있으니 나중에 등장할 것임

enum MoveDir
{
	MD_NONE,
	MD_LEFT,
	MD_RIGHT,
	MD_UP,
	MD_DOWN
};

extern MoveDir GMoveDir;

void HandleKeyInput();
void setCursorPosition(int x, int y);
void SetCursorOnOff(bool visible);