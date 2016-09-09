// Algorithm.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"

class KStack
{
public:
    KStack() : m_sp( 0 )
    {
    }
    void Push( int data_ );
    bool Pop( int& outData_ );
    bool IsEmpty() const;
private:
    int m_sp;
    int m_data[ 100 ];
};//class KStack

void KStack::Push( int data_ )
{
    m_data[ m_sp ] = data_;
    m_sp += 1;
}
bool KStack::Pop( int& outData_ )
{
    if( m_sp <= 0 ) return false;
    m_sp -= 1;
    outData_ = m_data[ m_sp ];
    return true;
}
bool KStack::IsEmpty() const
{
    return m_sp == 0;
}

void main()
{
    KStack s;
    s.Push( 3 );
    s.Push( 5 );
    int data;
    const bool bIsPop = s.Pop( data );
    printf( "%d\r\n", data );
}

