#include <iostream>

// This function will obtain a reference to the parameter 'r' and increment it.
void func( int &r ) { r++; }

// Template function.
template<class F, class P> void g( F f, P t ) { f( t ); }

int main() {
    int i = 0;
    g( func, i ); // 'g<void (int &r), int>' is instantiated
    // then 'i' will not be modified.
    std::cout << i << std::endl; // Output -> 0

    g( func, std::ref( i ) ); // 'g<void(int &r),reference_wrapper<int>>' is instantiated
    // then 'i' will be modified.
    std::cout << i << std::endl; // Output -> 1
}