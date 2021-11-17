#include <iostream>


template <typename T>
class Array {
public:
    Array() : size_(0), data_(nullptr) {
    }

    explicit Array(size_t size) : size_(size), data_(new T[size]){
    }

    ~Array() {
        delete[] data_;
    }

    size_t Size() const {
        return size_;
    }

    const T& operator[](size_t i) const {
        return data_[i];
    }

    T& operator[](size_t i) {
        return data_[i];
    }
    // ...
private:
    size_t size_;
    T* data_;
};

int main() {
    Array<int> numbers(3);
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