#include <stdio.h>

namespace std {

    template<typename T>
    class CVector
    {
        T   x;
        T   y;

    public:
        CVector();

        void Set( T tx, T ty );
        T GetX() { return x; }
        T GetY() { return y; }
    };// class CVector

}//namespace std

template<typename T>
std::CVector<T>::CVector()
{
    x = (T)0;
    y = (T)0;
}//CVector::CVector()

template<typename T>
void std::CVector<T>::Set( T tx, T ty )
{
    x = tx;
    y = ty;
}//void CVector<T>::Set(T tx, T ty)

template<typename T>
using Vector = std::CVector<T> ;

using IntType = int;

void main()
{
    Vector<int> v;
    IntType i;

    v.Set( 3, 4 );
    printf( "%d\n", v.GetY() );
}//main()