// Algorithm.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

template<typename T, int STACK_SIZE>
class KStack
{
public:
    KStack() : m_sp( 0 )
    {
    }
    void Push( T data_ );
    bool Pop( T& outData_ );
    bool IsEmpty() const;
private:
    int m_sp;
    T m_data[ STACK_SIZE ];
};//class KStack

template<typename T, int STACK_SIZE>
void KStack<T,STACK_SIZE>::Push( T data_ )
{
    m_data[ m_sp ] = data_;
    m_sp += 1;
}
template<typename T, int STACK_SIZE>
bool KStack<T, STACK_SIZE>::Pop( T& outData_ )
{
    if( m_sp <= 0 ) return false;
    m_sp -= 1;
    outData_ = m_data[ m_sp ];
    return true;
}
template<typename T, int STACK_SIZE>
bool KStack<T, STACK_SIZE>::IsEmpty() const
{
    return m_sp == 0;
}

void main()
{
    KStack<int, 100> s;
    int n;

    printf( "Enter decimal digit:" );
    scanf( "%d", &n );
    while( n >= 5 )
    {
        s.Push( n % 5 );
        n /= 5;
    }//while
    printf( "Equivalent Quintet is ", n );
    while( s.Pop( n ) )
        printf( "%d", n );
}//main
