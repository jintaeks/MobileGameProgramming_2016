// thread example
#include <iostream>
#include <thread>
#include <windows.h>

// Visual Studio 2013 doesn't support C++11 thread_local.
// Instead use __declspec(thread), which is Microsoft Visual Studio specific.
__declspec( thread ) int* g_pData = nullptr;

void foo( int i ) {
    if( g_pData == nullptr ) {
        g_pData = new int[ 11 ];
        printf( "g_pData allocated %i\r\n", i );
    }
    Sleep( 500 );
    printf( "%i\r\n", i );
    if( g_pData != nullptr ) {
        delete[] g_pData;
        printf( "g_pData destroyed %i\r\n", i );
    }
}

int main() {
    std::thread first( foo, 1 );     // spawn new thread that calls foo()
    std::thread second( foo, 3 );  // spawn new thread that calls bar(0)

    std::cout << "main, foo and foo now execute concurrently...\n";

    // synchronize threads:
    first.join();                // pauses until first finishes
    second.join();               // pauses until second finishes

    std::cout << "foo and bar completed.\n";

    return 0;
}
/*
g_pData allocated 1
g_pData allocated 3
main, foo and foo now execute concurrently...
1
g_pData destroyed 1
3
g_pData destroyed 3
foo and bar completed. */