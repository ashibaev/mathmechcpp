#include <cstdio>

void run(int* ptr) {
    int x = *ptr;
    if (!ptr) {
        printf("Null!\n");
        return;
    }
    *ptr = x;
}

int main() {
    int x = 0;
    scanf("%d", &x);
    run(x == 0 ? nullptr : &x);
}