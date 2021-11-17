#include <iostream>

template<class T, size_t N>
size_t array_size(T (&a)[N]){
    return N;
}

int main() {
    int p[] = {1, 2, 3, 4};
    std::cout << array_size(p) << std::endl;
}