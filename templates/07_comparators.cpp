#include <vector>
#include <stdexcept>
#include <iostream>

template <typename T, typename TComp>
T minimum(const std::vector<T>& array, TComp cmp){
    if (array.empty()) {
        throw std::invalid_argument("empty array");
    }
    T ans = array[0];
    for (int i = 0; i < array.size(); i++){
        if (cmp(array[i], ans)) ans = array[i];
    }
    return ans;
}

int main() {
    std::vector<int> vec({1, 2, 3});
    std::cout << minimum(vec, std::less<int>());
    std::cout << minimum(vec, std::greater<int>());
    return 0;
}