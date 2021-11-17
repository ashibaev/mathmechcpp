#include <iostream>

template <typename T>
void kek(T first, T second) {
    std::cout << "same type" << std::endl;
}

template <typename TFirst, typename TSecond>
void kek(TFirst first, TSecond second) {
    std::cout << "different types" << std::endl;
}

void kek(int first, int second) {
    std::cout << "ints" << std::endl;
}

int main() {
    kek(1, 2);
    return 0;
}
