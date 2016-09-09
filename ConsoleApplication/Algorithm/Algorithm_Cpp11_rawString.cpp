#include <stdio.h>

void main() {
    char* p0 = R"(The String Data \ Stuff " \r\n)";
    char* p1 = R"delimiter(The String Data \ Stuff " \r\n)delimiter";
    printf( "%s\r\n", p0 );
    printf( "%s\r\n", p1 );
}