#include <iostream>
#include "List.h"

int main()
{
	List li;

	li.AddAtTail(1); // 뒤에서부터 데이터 밀어넣음
	Node* node = li.AddAtTail(2); // 노드 위치 기억
	li.AddAtTail(3);

	li.Print();

	Node* node = li.GetNode(1); // 속도의 이점을 못 살림 (하나하나 찾기 때문)
	li.Remove(node);

	li.Print();

	return 0;
}

