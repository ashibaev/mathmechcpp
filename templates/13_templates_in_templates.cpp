#include <iostream>
#include <vector>

std::string ToString(int i) {
    return std::to_string(i);
}

template <template <typename> typename Container>
Container<std::string> ToStrings(const Container<int>& container) {
    Container<std::string> result(container.size());
    for (size_t i = 0; i < container.size(); ++i) {
        result[i] = ToString(container[i]);
    }
    return result;
}

int main() {
    std::vector<int> v{1, 2, 3};
    std::string s;
    for (auto&& x: ToStrings(v)) {
        s += x;
    }
    std::cout << s;
}