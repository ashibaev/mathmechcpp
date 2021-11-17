#include <cstdint>
#include <iostream>


int hash_code(std::string s) {
    int h = 13;
    for (char c : s) {
        h += h * 27752 + c;
    }
    if (h < 0) h += std::numeric_limits<int>::max();
    return h;
}

int main() {
    std::string s;
    std::cin >> s;
    std::cout << hash_code(s);
}
