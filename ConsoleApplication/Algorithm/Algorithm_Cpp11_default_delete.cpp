#include <type_traits>

struct X {
    // It means that you want to use the compiler-generated version
    // of that function, so you don't need to specify a body.
    X() = default;
};

struct Y {
    Y() {};
};

int main() {
    static_assert( std::is_trivial<X>::value, "X should be trivial" );
    static_assert( std::is_pod<X>::value, "X should be POD" );

    static_assert( !std::is_trivial<Y>::value, "Y should not be trivial" );
    static_assert( !std::is_pod<Y>::value, "Y should not be POD" );
}
/*
It means that you want to use the compiler-generated version
of that function, so you don't need to specify a body.

You can also use = delete to specify that you don't want the
compiler to generate that function automatically.

With the introduction of move constructors and move assignment operators,
the rules for when automatic versions of constructors, destructors
and assignment operators are generated has become quite complex.
Using = default and = delete makes things easier as you don't need
to remember the rules: you just say what you want to happen. */
