#include <vector>
#include <algorithm>
#include <locale>
#include <iostream>
#include <memory>
#include <stack>
#include <list>
#include <vector>
#include <functional> // to use std::greater<>()

struct greater
{
    bool operator()( int a, int b ) const
    {
        return a < b;
    }
};

int main() {
    std::list<int>  a;
    a.push_back(5);
    a.push_back(1);
    a.push_back(3);
    a.sort();

    for (int& t : a)
        printf("%i\r\n", t);

    std::vector<int>    b;
    b.push_back(5);
    b.push_back(1);
    b.push_back(3);
    //std::sort(b.begin(), b.end(), greater());
    std::sort(b.begin(), b.end(), std::greater<int>());

    for (int& t : b)
        printf("%i\r\n", t);
}
