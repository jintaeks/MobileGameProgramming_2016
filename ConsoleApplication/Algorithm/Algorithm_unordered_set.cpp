#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <unordered_set>

class KNode {
public:
    KNode(float fData) : m_fData(fData) {}
    float GetData() const {
        return m_fData;
    }
    bool operator==( const KNode& rhs ) const {
        return m_fData == rhs.m_fData;
    }
private:
    float m_fData;
};

class KNodeHash {
public:
    size_t operator()( const KNode& node ) const {
        return std::hash<float>()( node.GetData() );
    }
};

int main() {
    std::unordered_set<KNode, KNodeHash> uset;
    uset.insert( KNode( 1.f ) );
    uset.insert( KNode( 3.f ) );
    uset.insert( KNode( 2.f ) );

    auto sitor = uset.find( KNode( 2.f ) );
    if( sitor != uset.end() ) {
        std::cout << ( *sitor ).GetData() << std::endl;
    }//if
}//int main()
