#include <iostream>
#include <memory>

template<typename T>
class KWrapper {
public:
    KWrapper( T data ) : mData( data ) {
    }
    void Print() const {
        std::cout << mData << std::endl;
    }
private:
    T   mData;
};

template<typename T>
class KWrapper<T*> {
public:
    KWrapper( T* data ) : mData( data ) {
    }
    void Print() const {
        std::cout << *mData << std::endl;
    }
private:
    T*   mData;
};

template<>
class KWrapper<char*> {
public:
    KWrapper( char* data ) : mData( data ) {
    }
    void Print() const;
    //void Print() const {
    //    std::cout << mData << std::endl;
    //}
private:
    char*   mData;
};

//template<>
void KWrapper<char*>::Print() const {
    std::cout << mData << std::endl;
}

int main() {
    KWrapper<int> a( 1 );
    a.Print();

    int i = 3;
    KWrapper<int*> b( &i );
    b.Print();

    char* p = "hello";
    KWrapper<char*> c( p );
    c.Print();
}//int main()
