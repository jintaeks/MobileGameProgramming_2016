#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> some_list{ 1, 2, 3, 4, 5 };
    int total = 0;
    std::for_each( begin( some_list ), end( some_list ), [&total]( int x ) {
        total += x;
    } );
    printf( "%i\r\n", total );
}

class KTest {
public:
    int some_func() const { return 2; }
    void Test() {
        std::vector<int> some_list{ 1, 2, 3, 4, 5 };
        int total = 0;
        int value = 5;
        std::for_each( begin( some_list ), end( some_list ), [&, value, this]( int x ) {
            total += x * value * this->some_func();
        } );
    }
};
