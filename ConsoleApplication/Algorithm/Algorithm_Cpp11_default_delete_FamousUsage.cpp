#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

class KData {
public:
    KData( const KData& rhs ) = delete;
    KData& operator=( const KData& rhs ) = delete;
    KData( int i ) : m_iData{ i } {}
public:
    int m_iData = 0;
};

int main() {
    std::vector<KData>  v;

    v.push_back( { 1 } );
    return 0;
}