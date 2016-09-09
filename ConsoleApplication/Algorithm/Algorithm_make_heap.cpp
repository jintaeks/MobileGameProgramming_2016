#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> v{ 3, 1, 4, 1, 5, 9 };

    std::make_heap( v.begin(), v.end() );

    std::cout << "v: ";
    for( auto i : v ) std::cout << i << ' ';
    std::cout << '\n';

    std::pop_heap( v.begin(), v.end() ); // moves the largest to the end

    std::cout << "after pop_heap: ";
    for( auto i : v ) std::cout << i << ' ';
    std::cout << '\n';

    int largest = v.back();
    v.pop_back();  // actually removes the largest element
    std::cout << "largest element: " << largest << '\n';

    std::cout << "heap without largest: ";
    for( auto i : v ) std::cout << i << ' ';
    std::cout << '\n';

    //Pushes the node onto the back of the vector (the heap is now unsorted)
    std::cout << "after push heap: ";
    v.push_back( 5 );
    //Sorts the new element into the heap
    std::push_heap( v.begin(), v.end() );

    for( auto i : v ) std::cout << i << ' ';
    std::cout << '\n';

    /*
    v: 9 5 4 1 1 3
    after pop_heap: 5 3 4 1 1 9
    largest element: 9
    heap without largest: 5 3 4 1 1
    after push heap: 5 3 5 1 1 4
    */
}