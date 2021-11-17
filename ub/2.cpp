#include <vector>
#include <numeric>
#include <iostream>

int average(const std::vector<int>& v) {
    if (v.empty()) {
        return 0;
    }
    return std::accumulate(v.begin(), v.end(), 0) / static_cast<int>(v.size());
}

int main() {
    std::cout << average({-1,-1,-1});
}
