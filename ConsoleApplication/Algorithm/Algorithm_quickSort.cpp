#include <vector>
#include <algorithm>
#include <iostream>

#define ARRAY_SIZE(a)   (sizeof(a)/sizeof(a[0]))

void quickSort( int arr[], int left, int right ) {
    int i = left, j = right;
    int tmp;
    int pivot = ( left + right ) / 2;

    /* partition */
    while( i <= j ) {
        while( arr[ i ] < arr[pivot] )
            i++;
        while( arr[ j ] > arr[pivot] )
            j--;
        if( i <= j ) {
            tmp = arr[ i ];
            arr[ i ] = arr[ j ];
            arr[ j ] = tmp;
            i++;
            j--;
        }
    };

    /* recursion */
    if( left < j )
        quickSort( arr, left, j );
    if( i < right )
        quickSort( arr, i, right );
}
int main() {
    int data[] = { 1, 12, 5, 26, 7, 14, 3, 7, 2 };
    quickSort( data, 0, ARRAY_SIZE( data ) - 1 );
    std::for_each( data, data + ARRAY_SIZE( data ), []( int n ) {printf( "%i ", n ); } );
}
