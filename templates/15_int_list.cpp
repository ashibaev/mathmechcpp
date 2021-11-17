#include <iostream>
#include <tuple>

template<int... Ints>
struct IntList;

template<int First, int... Other>
struct IntList<First, Other...>
{
    static int const Head = First;
    using Tail = IntList<Other...>;
};

template<>
struct IntList<>{};


using List = IntList<1, 2, 3, 4, 5>;


int main() {
    std::cout << List::Head << ' ' << List::Tail::Head << std::endl;
    return 0;
}