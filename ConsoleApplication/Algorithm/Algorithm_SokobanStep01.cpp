#include <iostream>
#include <algorithm>
#include <vector>
#include <conio.h>
#include <windows.h>

#pragma comment(lib, "winmm.lib")

#define ARRAY_SIZE(a)   (sizeof(a)/sizeof(a[0]))

enum EArrowKey {
    ARROWKEY_UP = 72,
    ARROWKEY_LEFT = 75,
    ARROWKEY_RIGHT = 77,
    ARROWKEY_DOWN = 80,
};

class KInputKey {
public:
    void    Update( int iKeyValue_ ) {
        const int aKey[] = {ARROWKEY_UP, ARROWKEY_LEFT, ARROWKEY_RIGHT, ARROWKEY_DOWN };
        for( int i = 0; i < ARRAY_SIZE(aKey); ++i ) {
            if( aKey[ i ] == iKeyValue_ ) {
                mKeyValue = iKeyValue_;
                mArrowKeyStamp += 1;
            }
        }
    }//Update()

    DWORD   GetStamp() const { return mArrowKeyStamp; }
    int     GetKey() const { return mKeyValue; }

private:
    int         mKeyValue = 0;
    DWORD       mArrowKeyStamp = 0;
};

bool        gIsRunGameLoop = true;
KInputKey   gInputKey;

void OnFrameMove( DWORD dwElapsedTime ) {
    //std::cout << __FUNCTION__ << std::endl;
    //std::cout << dwElapsedTime << std::endl;
    static DWORD dwInputKeyStamp = 0L;
    if( dwInputKeyStamp != gInputKey.GetStamp() ) {
        dwInputKeyStamp = gInputKey.GetStamp();
        std::cout << gInputKey.GetKey() << std::endl;
    }
}//OnFrameMove()

void OnFrameRender( DWORD dwElapsedTime ) {
    //std::cout << __FUNCTION__ << std::endl;
}//OnFrameRender()

int main() {
    DWORD dwPrevTime = timeGetTime();

    while( gIsRunGameLoop == true ) {
        if( _kbhit() ) {
            int iKeyValue = _getch();
            //std::cout << g_iKey << std::endl;
            if( iKeyValue == 27 )
                gIsRunGameLoop = false;
            else if( iKeyValue == 0 ) {
                iKeyValue = _getch();
                gInputKey.Update( iKeyValue );
            }
        }
        const DWORD dwNewTime = timeGetTime();
        const DWORD dwElapsedTime = dwNewTime - dwPrevTime;
        dwPrevTime = dwNewTime;

        OnFrameMove( dwElapsedTime );
        OnFrameRender( dwElapsedTime );

        Sleep( 50 );
    }//while
}//main()
