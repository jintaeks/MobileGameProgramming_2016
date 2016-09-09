#include <stdio.h>

class CData
{
    int data;
public:
    CData( int d = 0 )
    {
        data = d;
    }
    void DoIt()
    {
        printf( "data=%d\n", data );
    }//DoIt()
};//class CTest


template<class T>
class vector
{
public:
    typedef T* iterator;

public:
    T   m_data[ 100 ];
    int m_begin;
    int m_end;

    vector();
    T& operator[]( int i ) { return m_data[ i ]; }
    void push_back( T& d );
    T* begin();
    T* end();

};//class vector

template<class T>
vector<T>::vector()
{
    m_begin = 0;
    m_end = 0;
}

template<class T>
void vector<T>::push_back( T& d )
{
    m_data[ m_end++ ] = d;
}

template<class T>
T* vector<T>::begin()
{
    return &m_data[ m_begin ];
}

template<class T>
T* vector<T>::end()
{
    return &m_data[ m_end ];
}

void main()
{
    CData d1( 1 ), d2( 2 ), d3( 3 );
    vector<CData> vec;

    vec.push_back( d1 );
    vec.push_back( d2 );
    vec.push_back( d3 );

    vec[ 1 ].DoIt();

    vector<CData>::iterator iter;

    for( iter = vec.begin(); iter != vec.end(); iter++ ) {
        ( *iter ).DoIt();
    }//for

    for( CData& d : vec ) {
        d.DoIt();
    }
}//main()
