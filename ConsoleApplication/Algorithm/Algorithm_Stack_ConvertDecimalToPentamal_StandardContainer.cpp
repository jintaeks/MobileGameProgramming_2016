// Algorithm.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <stack>

void main()
{
    std::stack<int> s;
    int n;

    printf( "Enter decimal digit:" );
    scanf( "%d", &n );
    while( n >= 5 )
    {
        s.push( n % 5 );
        n /= 5;
    }//while
    printf( "Equivalent Quintett is %d", n );
    while( s.empty() == false )
    {
        n = s.top();
        printf( "%d", n );
        s.pop();
    }//while
}//main
