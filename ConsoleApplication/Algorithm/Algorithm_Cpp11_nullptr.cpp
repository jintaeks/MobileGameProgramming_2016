#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

class KPointer {
public:
    template<typename T>
    KPointer& operator=( T rhs ) = delete;

    KPointer& operator=( char* rhs ) {
        m_pData = rhs;
        return *this;
    }
    // do not use like this. it's just example.
    KPointer& operator=( nullptr_t rhs ) {
        delete m_pData;
        m_pData = nullptr;
        return *this;
    }

public:
    char* m_pData;
};

int main() {
    KPointer t;
    t = new char;
    //t = 0;
    t = nullptr;
    return 0;
}