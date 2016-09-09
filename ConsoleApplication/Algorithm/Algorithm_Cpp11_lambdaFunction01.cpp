#include <iostream>
#include <map>

int CompFunc( int left_, int right_ ) {
    return left_ < right_;
}

class KCompare {
public:
    int operator()( int left_, int right_ ) const {
        return left_ < right_;
    }
};

template<typename T>
void CompareTest( int a, int b, T predicate_ ) {
    //const bool bCompResult = predicate_.operator()(a, b);
    const bool bCompResult = predicate_( a, b );
    printf( "CompareTest result = %d\r\n", bCompResult );
}

int main() {
    CompareTest( 2, 3, CompFunc );
    CompareTest( 2, 3, KCompare() );
    auto compareLambda = []( int a, int b )->int {return a < b; };
    CompareTest( 2, 3, compareLambda );
    CompareTest( 2, 3, []( int a, int b )->int {return a < b; } );

    int total = 0;
    auto add = [&total]( int a ) { total += a; };
    add( 3 );
    // you can directly call lambda. jintaeks on 2016-06-27_13-13
    [&total]( int a ) { total += a; }( 5 );
    printf( "%d\r\n", total );
}
