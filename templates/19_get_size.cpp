#include <iostream>

template<class T, size_t (T::*)() const = &T::size>
size_t get_size(T const& t)
{
    return t.size();
}

template<class T, size_t (T::*) = &T::size>
size_t get_size(T const& t)
{
    return t.size;
}

int main() {
    std::string s{"Hello"};
    std::cout << get_size(s) << std::endl;

    struct Struct
    {
        size_t size = 0;
    };

    Struct x{10};
    std::cout << get_size(x) << std::endl;
}