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


template<typename T>
struct Length{
    static const size_t value = 1 +
                                Length<typename T::Tail>::value;
};

template<>
struct Length<IntList<>>{
    static const size_t value = 0;
};

using primes = IntList<2,3,5,7,11,13>;
constexpr int head = primes::Head;
using odd_primes = primes::Tail;


int main() {
    std::cout << Length<primes>::value << std::endl;
    return 0;
}