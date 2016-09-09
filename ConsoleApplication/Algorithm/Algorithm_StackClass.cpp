// Algorithm.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

class KStack
{
public:
    KStack() : m_sp( 0 )
    {
    }
    void Push( int data_ )
    {
        m_data[ m_sp ] = data_;
        m_sp += 1;
    }
    bool Pop( int& outData_ )
    {
        if( m_sp <= 0 ) return false;
        m_sp -= 1;
        outData_ = m_data[ m_sp ];
        return true;
    }
    bool IsEmpty() const
    {
        return m_sp == 0;
    }
private:
    int m_sp;
    int m_data[ 100 ];
};//class KStack

void main()
{
    KStack s;
    s.Push( 3 );
    s.Push( 5 );
    int data;
    const bool bIsPop = s.Pop( data );
    printf( "%d\r\n", data );
}

