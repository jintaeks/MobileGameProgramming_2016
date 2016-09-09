#include <iostream>
//#include <memory>
#include <type_traits>

void printf2( const char *s ) {
    while( *s ) {
        if( *s == '%' ) {
            if( *( s + 1 ) == '%' ) {
                ++s;
            } else {
                throw std::runtime_error( "invalid format string: missing arguments" );
            }
        }
        std::cout << *s++;
    }
}

template<typename T, typename... Args>
void printf2( const char *s, T value, Args... args ) {
    while( *s ) {
        if( *s == '%' ) {
            if( *( s + 1 ) == '%' ) {
                ++s;
            } else {
                std::cout << value;
                s += 2; // this only works on 2 characters format strings ( %d, %f, etc ). Fails miserably with %5.4f
                printf2( s, args... ); // call even when *s == 0 to detect extra arguments
                return;
            }
        }
        std::cout << *s++;
    }
}

void main() {
    int i = 3;
    int j = 5;
    printf2( "%i %i\r\n", i, j );
}//int main()
