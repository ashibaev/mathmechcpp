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


using primes = IntList<2,3,5,7,11,13>;
constexpr int head = primes::Head;
using odd_primes = primes::Tail;


template<int H, typename IL>
struct IntCons;

template<int H, int... T>
struct IntCons<H, IntList<T...>>{
    using type = IntList<H, T...>;
};

template<int Max, int Min = 0>
struct Generate{
    using type = typename IntCons<Min, typename Generate<Max, Min + 1>::type>::type;
};

template<int Max>
struct Generate<Max, Max>{
    using type = IntList<>;
};


template<typename Func, typename... Args, int... Ints>
auto calc(
    Func f, const std::tuple<Args...>& t, IntList<Ints...>
) -> decltype(f(std::get<Ints>(t)...))
{
    return f(std::get<Ints>(t)...); // Ints = 0, 1, 2 -> f(std::get<0>(t), std::get<1>(t), std::get<2>(t));
}

template<typename Func, typename... Args>
auto apply(
    Func f,
    const std::tuple<Args...>& t
) -> decltype(
        calc(f, t, typename Generate<(int)sizeof...(Args)>::type())
    )
{
    return calc(f, t, typename Generate<(int)sizeof...(Args)>::type());
}


int main() {
    auto f = [](int x, double y, double z) { return x + y + z; };
    auto t = std::make_tuple(30, 5.0, 1.6);  // std::tuple<int, double, double>
    auto res = apply(f, t);

    std::cout << res << std::endl;
    return 0;
}