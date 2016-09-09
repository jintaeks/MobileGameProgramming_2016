#include <type_traits>
#include <stdio.h>

template<bool B, class T, class F>
struct conditional { typedef T type; };

template<class T, class F>
struct conditional<false, T, F> { typedef F type; };

template <typename... Args>
struct find_biggest;

// the biggest of one thing is that one thing
template <typename First>
struct find_biggest<First> {
    typedef First type;
};

// the biggest of everything in Args and First
//template <typename First, typename... Args>
//struct find_biggest<First, Args...> {
//    static const int size = sizeof...( Args ) + 1;
//    typedef typename find_biggest<Args...>::type next;
//    typedef typename conditional< sizeof( First ) >= sizeof(next)
//        , First, next>::type type;
//};

template <typename First, typename... Args>
struct find_biggest<First, Args...> {
    typedef typename conditional<
        sizeof( First ) >= sizeof( typename find_biggest<Args...>::type )
        , First, typename find_biggest<Args...>::type>::type type;
};

void main() {
    find_biggest<char, long long, float, short>::type i;

    printf( "%i\r\n", sizeof( i ) );
    //printf( "%i %i\r\n", sizeof( i ), find_biggest<char, long long, float, short>::size );
}
