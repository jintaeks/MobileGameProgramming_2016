// declare_reachable / undeclare_reachable example
#include <iostream>
#include <memory>
#include <cstdint>

int main() {
    int * p = new int( 1 );    // dynamic object

    std::declare_reachable( p );

    p = (int*)( ( std::uintptr_t )p ^ UINTPTR_MAX );  // scrambling p

    // dynamic object not reachable by any live safely-derived pointer

    p = std::undeclare_reachable( (int*)( ( std::uintptr_t )p ^ UINTPTR_MAX ) );
    // p is back again a safely-derived pointer to the dynamic object

    std::cout << "p: " << *p << '\n';
    delete p;

    return 0;
}
/*
    When someday, garbage collector added into the C++ library. We need to tell to
    the garbage collector about that do not delete 'p' pointer it will be reachable later in my code.
    To tell this, we need to call std::declare_reachable(p);.
    In above example, if we do not call std::declare_reachable(p);,
    the pointer 'p' to dynamic object can be destroyed by the garbage collector
    cause there is no live pointer to dynamic object by 'scrambling p' statement.
    To prevent this situation, we must tell to the garbage collector about reachableness of pointer to dynamic object.
    std::declare_reachable() is used for this purpose.
    jintaeks on 2016-03-18_22-04
*/