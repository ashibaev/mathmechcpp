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


template<int H, typename IL>
struct IntCons;

template<int H, int... T>
struct IntCons<H, IntList<T...>>{
    using type = IntList<H, T...>;
};

template<typename First, typename Second, template<int, int> class Func>
struct Zip{
    using type = typename IntCons<Func<First::Head, Second::Head>::value,
            typename Zip<typename First::Tail, typename Second::Tail, Func>::type>::type;
};

template<template<int, int> class Func>
struct Zip<IntList<>, IntList<>, Func>{
    using type = IntList<>;
};

template<int a, int b>
struct Plus
{
    static int const value = a + b;
};


using L1 = IntList<1,2,3,4,5>;
using L2 = IntList<1,3,7,7,2>;

using L3 = Zip<L1, L2, Plus>::type;

template <typename T>
void print_list(std::ostream &out) {
    out << T::Head << ' ';
    print_list<typename T::Tail>(out);
}

template <>
void print_list<IntList<>>(std::ostream& out) {
}

int main() {
    std::cout << Length<primes>::value << std::endl;
    print_list<L3>(std::cout);
    return 0;
}



