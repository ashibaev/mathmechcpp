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

template <>
class Array<bool> {
public:
    Array() : size_(0), data_(nullptr) {
    }

    explicit Array(size_t size) : size_(size), data_(new size_t[(size + BITS_COUNT - 1) / BITS_COUNT]){
    }

    ~Array() {
        delete[] data_;
    }

    size_t Size() const {
        return size_;
    }

    bool operator[](size_t i) const {
        return bool(data_[i / BITS_COUNT] & (size_t(1) << (i % BITS_COUNT)));
    }


private:
    size_t size_;
    size_t* data_;

    static size_t const BITS_COUNT = 8 * sizeof(size_t);
};



int main() {
    Array<bool> numbers(3);
    for (size_t i = 0; i < numbers.Size(); ++i) {
        std::cin >> numbers[i];
    }
    int sum = 0;
    for (size_t i = 0; i < numbers.Size(); ++i) {
        sum += numbers[i];
    }
    std::cout << sum << std::endl;

    numbers[0] = false;
    numbers[1] = true;
    numbers[2] = false;
    sum = 0;
    for (size_t i = 0; i < numbers.Size(); ++i) {
        sum += numbers[i];
    }
    std::cout << sum;
    return 0;
}