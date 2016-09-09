#include <string>
#include <iostream>
#include <iomanip>
#include <utility>

struct A {
    std::string s;
    A() : s( "test" ) { std::cout << "constructor A\n"; }
    A( const A& o ) : s( o.s ) { std::cout << "copy constructor A\n"; }
    A( A&& o ) : s( std::move( o.s ) ) { std::cout << "move constructor A\n"; }
};

A f( A a ) {
    return a;
}

struct B : public A {
    std::string s2;
    int n;
    // we expect below things:
    // implicit move constructor B::(B&&)
    // calls A's move constructor
    // calls s2's move constructor
    // and makes a bitwise copy of n
    // but in Visual Studio 2013, implicit functions do not call base class's special functions.
    // jintaeks on 2016-03-19_17-12
};

B g( B b ) {
    return b;
}

struct C : public A {
    std::string s2;
    int n;

    C() : A() { std::cout << "constructor C\n"; }
    C( const C& o ) : A(o) { std::cout << "copy constructor C\n"; }
    C( C&& o ) : A( std::move( o ) ) { std::cout << "move constructor C\n"; }
    //C( C&& o ) : A( o ) { std::cout << "move constructor C\n"; }
};

C h( C c ) {
    return c;
}

int main() {
    std::cout << "Trying to move A\n";
    A a1 = f( A() ); // move-construct from rvalue temporary
    std::cout << "Before move, a1.s = " << a1.s << "\n";
    A a2 = std::move( a1 ); // move-construct from xvalue
    std::cout << "After move, a1.s = " << a1.s << "\n";

    std::cout << "Trying to move B\n";
    B b1 = g( B() );
    std::cout << "Before move, b1.s = " << b1.s << "\n";
    B b2 = std::move( b1 ); // calls implicit move ctor
    std::cout << "After move, b1.s = " << b1.s << "\n";

    std::cout << "Trying to move C\n";
    C c1 = h( C() );
    std::cout << "Before move, c1.s = " << c1.s << "\n";
    C c2 = std::move( c1 ); // calls the move constructor
    std::cout << "After move, c1.s = " << c1.s << "\n";
}
