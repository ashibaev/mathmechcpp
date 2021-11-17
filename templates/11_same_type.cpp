#include <iostream>

template<class T, class V>
struct IsSameType{
    static const bool value = false;
};

template<class T>
struct IsSameType<T, T>{
    static const bool value = true;
};

int main() {
    std::cout << IsSameType<int, bool>::value << ' ' << IsSameType<int, int>::value << std::endl;
}