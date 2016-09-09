#include <iostream>
#include <memory>

void Test( std::shared_ptr<int> spInt_ ) {
}

int main() {
    typedef std::shared_ptr<int>     IntPtr;
    IntPtr spInt( new int( 3 ) );

    if( spInt != NULL ) {
        std::cout << *spInt << std::endl;
    }//if

    IntPtr spInt2 = spInt;
    IntPtr spInt3 = spInt;

    spInt.reset( new int( 4 ) );
    *spInt = 5;
    if( spInt2 != NULL ) {
        std::cout << *spInt << std::endl;
    }//if
    //int* p = spInt;

    //if( spInt < spInt )
    //{
    //}

    //int iData = 5;
    //Test( &iData );

    return 0;
    /** output:
    3
    5
    계속하려면 아무 키나 누르십시오 . . .
    */
}//int main()
