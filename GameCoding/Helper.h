 #pragma once // include�� ������ �ص� �ѹ��� �߰��ǰ� �� (��� ����)
			
//void Test(int);
//void Test2();
//#define TEST 3
//enum PlayerType
//{
//	Knight,
//	Mage
//};
//extern int Gtest; // =�� ������ �ܺο� ������ ���߿� ������ ����

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