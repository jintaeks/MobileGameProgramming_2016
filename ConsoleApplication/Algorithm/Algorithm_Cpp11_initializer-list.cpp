#include <initializer_list>
#include <iostream>
#include <algorithm>
#include <numeric>

struct S {
    int thesum;
    int items;
    S( std::initializer_list<int> l ) :
        thesum{ std::accumulate( l.begin(), l.end(), 0 ) },
        items( l.size() ) {
    }
};

int main() {
    std::initializer_list<int> i = {1,3,5};
    S s = { 1, 2, 3 };

    std::cout << s.items << std::endl;
    std::cout << s.thesum << std::endl;
    return 0;
}