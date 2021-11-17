#include <iostream>

const int N = 4;
int elements[N];

bool contains(int x) {
    for (int i = 0; i <= N; ++i) {
        if (x == elements[i]) {
            return true;
        }
    }
    return false;
}

int main() {
    for (int i = 0; i < N; ++i) {
        std::cin >> elements[i];
    }
    return contains(5);
}