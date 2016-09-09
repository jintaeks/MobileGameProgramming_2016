#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

int main() {
    std::vector<int> v = { 1, 3, 5, 2 };
    std::sort( v.begin(), v.end(), std::not2( std::less<int>() ) );
    //std::sort( v.begin(), v.end(), std::greater<int>() );
    std::for_each( v.begin(), v.end(), []( int n ) { std::cout << n << std::endl;  } );
}//int main()
