#include <iostream>

class ArrayFloat {
public:
    explicit ArrayFloat(size_t size) : size_(size), data_(new float[size]){
    }

    ~ArrayFloat() {
        delete[] data_;
    }

    size_t Size() const {
        return size_;
    }

    float operator[](size_t i) const {
        return data_[i];
    }

    float& operator[](size_t i) {
        return data_[i];
    }
    // ...
private:
    size_t size_;
    float* data_;
};

int main() {
    ArrayFloat numbers(3);
    for (size_t i = 0; i < numbers.Size(); ++i) {
        std::cin >> numbers[i];
    }
    float sum = 0;
    for (size_t i = 0; i < numbers.Size(); ++i) {
        sum += numbers[i];
    }
    std::cout << sum;
    return 0;
}