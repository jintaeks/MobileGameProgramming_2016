#include <iostream>

// will not compiled!
template<typename T, typename U>
decltype(T+U) add( T t, U u )
{
    return t + u;
}

template<typename T, typename U>
auto add2( T t, U u ) -> decltype( t + u ) // return type depends on template parameters
{
    return t + u;
}

int main() {
    int i = 3;
    decltype( i ) j = i * 2;
    printf( "%i %i\r\n", i, j );

    auto f = []( int a, int b ) -> int {
        return a * b;
    };
    decltype( f ) g = f; // the type of a lambda function is unique and unnamed
    i = f( 2, 2 );
    j = g( 3, 3 );
    printf( "%i %i\r\n", i, j );

    std::cout << add2( 2, 3 ) << std::endl;
}