#include <iostream>

int main() {
    int x = 2'000'000'000;
    int y = 0;
    std::cin >> y;

    if (x > 0 && y > 0 && x + y <=0){
        return 5;
    }
    return 0;
}