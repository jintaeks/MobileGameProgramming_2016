#include <vector>
#include <algorithm>
#include <iostream>

#define ARRAY_SIZE(a)   (sizeof(a)/sizeof(a[0]))

template<typename T, typename COMP>
void quickSort( T arr[], int left, int right, COMP comp) {
    int i = left, j = right;
    T pivot = ( left + right ) / 2;

    /* partition */
    while( i <= j ) {
        while( comp( arr[ i ], arr[pivot] ) == true )
            i++;
        while( comp( arr[ pivot ], arr[ j ] ) == true )
            j--;
        if( i <= j ) {
            T tmp = arr[ i ];
            arr[ i ] = arr[ j ];
            arr[ j ] = tmp;
            i++;
            j--;
        }
    };

    /* recursion */
    if( left < j )
        quickSort( arr, left, j, comp );
    if( i < right )
        quickSort( arr, i, right, comp );
}

int main() {
    int data[] = { 1, 12, 5, 26, 7, 14, 3, 7, 2 };
    quickSort( data, 0, ARRAY_SIZE( data ) - 1, []( int a, int b ) { return a < b;  } );
    std::for_each( data, data + ARRAY_SIZE( data ), []( int n ) {printf( "%i ", n ); } );
}