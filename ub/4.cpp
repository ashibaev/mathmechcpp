#include <iostream>

int main() {
    uint8_t port = 0x5a;  // 01011010 -> 0000000000001011010 ~> 1111111111110100101
    uint8_t result_8 = ( ~port ) >> 4;  // 11111010
    std::cout << int(result_8);
    return 0;
}