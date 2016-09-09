// Algorithm.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <iostream>
#include <list>

void Test(std::initializer_list<int> l_)
{
}

int main()
{
	std::list<int> intList;

	intList.assign({ 1, 3, 5 });
	//Test({ 1, 3, 5 });

	for (int c : intList) {
		std::cout << c << '\n';
		// 1, 3, 5
	}

	std::list<int>::iterator	listHandle = intList.begin();
	listHandle++; // listHandle indicates node '3'

	intList.insert(listHandle, 9); // 1, 9, 3, 5 and listHandle indicates '3' consistently
	intList.insert(listHandle, 99); // 1, 9, 99, 3, 5

	for (int c : intList) {
		std::cout << c << '\n';
	}

	return 0;
}
