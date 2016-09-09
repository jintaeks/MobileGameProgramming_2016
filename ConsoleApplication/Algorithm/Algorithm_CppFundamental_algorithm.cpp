#include <vector>
#include <algorithm>
#include <iostream>

struct Sum {
    Sum() : sum{ 0 } {}
    void operator()( int n ) { sum += n; }
    int sum;
};

int main() {
    std::vector<int> nums{ 3, 4, 2, 8, 15, 267 };

    std::cout << "before:";
    for( auto const &n : nums ) {
        std::cout << ' ' << n;
    }
    std::cout << '\n';

    std::for_each( nums.begin(), nums.end(), []( int &n ) { n++; } );

    //int total = 0;
    //std::for_each( nums.begin(), nums.end(), [&total]( const int&n ) { total += n; } );
    //std::cout << total << std::endl;

    // calls Sum::operator() for each number
    Sum s;
    std::for_each( nums.begin(), nums.end(), std::ref(s) );

    std::cout << "after: ";
    for( auto const &n : nums ) {
        std::cout << ' ' << n;
    }
    std::cout << '\n';
    std::cout << "sum: " << s.sum << '\n';

    // std::sort() example
    //
    std::vector<int> v = { 1, 3, 5, 2 };
    std::sort( v.begin(), v.end(), std::not2( std::less<int>() ) );
    //std::sort( v.begin(), v.end(), std::greater<int>() );
    std::for_each( v.begin(), v.end(), []( int n ) { std::cout << n << std::endl;  } );
}