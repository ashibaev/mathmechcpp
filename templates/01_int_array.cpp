#include <iostream>

class ArrayInt {
public:
    explicit ArrayInt(size_t size) : size_(size), data_(new int32_t[size]){
    }

    ~ArrayInt() {
        delete[] data_;
    }

    size_t Size() const {
        return size_;
    }

    int32_t operator[](size_t i) const {
        return data_[i];
    }

    int32_t& operator[](size_t i) {
        return data_[i];
    }
    // ...
private:
    size_t size_;
    int32_t* data_;
};

int main() {
    ArrayInt numbers(3);
    for (size_t i = 0; i < numbers.Size(); ++i) {
        std::cin >> numbers[i];
    }
    int sum = 0;
    for (size_t i = 0; i < numbers.Size(); ++i) {
        sum += numbers[i];
    }
    std::cout << sum;
    return 0;
}