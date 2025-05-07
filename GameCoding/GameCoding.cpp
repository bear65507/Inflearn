#include <iostream>
#include <vector>
using namespace std;
#include "BinarySearchTree.h"

// 이진 탐색 -> O(log N) but 정렬 필요, 데이터 추가/삭제 어려움
// 이진 탐색 트리 -> 데이터를 추가/삭제하다 보면 균형 잡힌 트리를 만들기 어려움
// --> 한 쪽으로만 늘어난 트리는 시간복잡도가 O(N)이 됨, 사실상 연결리스트
// --> 균형 잡힌 트리를 만드는 대안 : 레드-블랙 트리, AVL

int main()
{
	BinarySearchTree bst;

	bst.Insert(20);
	bst.Insert(30);
	bst.Insert(10);

	bst.Insert(25);
	bst.Insert(26);
	bst.Insert(40);
	bst.Insert(50);

	bst.Delete(26);

	bst.Print();
	return 0;
}