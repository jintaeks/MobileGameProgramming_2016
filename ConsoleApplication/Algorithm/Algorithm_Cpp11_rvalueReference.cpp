#include <iostream>
#include <algorithm>
#include <vector>

class KTest {
public:
    KTest() {
        std::cout << "constructor\r\n";
    }
    KTest( const KTest& rhs ) {
        std::cout << "copy constructor\r\n";
    }
    KTest( const KTest&& rhs ) {
        std::cout << "move constructor\r\n";
    }
    ~KTest() {
        std::cout << "destructor\r\n";
    }
};

void F( KTest t ) {
    //return t;
}

void G( const KTest& t ) {
    std::cout << "lvalue ref G " << std::endl;
}

void G( KTest&& t ) {
    KTest u = std::move( t );
    //KTest u = t;
    std::cout << "rvalue ref G " << std::endl;
}

int main() {
    KTest t;
    KTest u = t;
    F( KTest() );
    F( t );
    std::cout << "\r\nbefore call G\r\n";
    G( KTest() );
    G( t );
}
