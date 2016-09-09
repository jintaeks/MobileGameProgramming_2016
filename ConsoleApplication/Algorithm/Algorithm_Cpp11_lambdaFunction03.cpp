#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

double eval( std::function <double( double )> f, double x = 2.0 ) {
    return f( x );
}

int main() {
    // use 'auto' to dynamically create lambda object.
    //
    auto my_lambda_func = [&]( int x ) { /*...*/ };
    auto my_onheap_lambda_func = new auto( [=]( int x ) { /*...*/ } );

    // lambda can be assigned to a function pointer, when the capture list is emtpy.
    //
    auto a_lambda_func = []( int x ) { /*...*/ };
    void( *func_ptr )( int ) = a_lambda_func;
    func_ptr( 4 ); //calls the lambda.

    // various usage of lambda.
    //
    std::function<double( double )> f0 = []( double x ) {return 1; };
    auto                          f1 = []( double x ) {return x; };
    decltype( f0 )                  fa[ 3 ] = { f0, f1, []( double x ) {return x*x; } };
    std::vector<decltype( f0 )>     fv = { f0, f1 };
    fv.push_back( []( double x ) {return x*x; } );
    for( int i = 0; i<fv.size(); i++ )
        std::cout << fv[ i ]( 2.0 ) << std::endl;
    for( int i = 0; i<3; i++ )
        std::cout << fa[ i ]( 2.0 ) << std::endl;
    for( auto &f : fv )
        std::cout << f( 2.0 ) << std::endl;
    for( auto &f : fa )
        std::cout << f( 2.0 ) << std::endl;
    std::cout << eval( f0 ) << std::endl;
    std::cout << eval( f1 ) << std::endl;
    std::cout << eval( []( double x ) {return x*x; } ) << std::endl;
    return 0;
}