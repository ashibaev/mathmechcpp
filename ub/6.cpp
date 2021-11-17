#include <string>
#include <iostream>
#include <vector>
#include <numeric>

int main() {
    std::vector<char> x = {48, 49, 50};
    std::string s;
    s += 48;
    s += 49;
    s += 49.5;
    std::cout << std::accumulate(x.begin(), x.end(), s);
    return 0;
}