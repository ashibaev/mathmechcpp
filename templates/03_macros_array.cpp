#include <iostream>


#define DEFINE_ARRAY(Name, Type)                                             \
class Name {                                                                 \
public:                                                                      \
    explicit Name(size_t size) : size_(size), data_(new Type[size]){         \
    }                                                                        \
                                                                             \
    ~Name() {                                                                \
        delete[] data_;                                                      \
    }                                                                        \
                                                                             \
    size_t Size() const {                                                    \
        return size_;                                                        \
    }                                                                        \
                                                                             \
    Type operator[](size_t i) const {                                        \
        return data_[i];                                                     \
    }                                                                        \
                                                                             \
    Type& operator[](size_t i) {                                             \
        return data_[i];                                                     \
    }                                                                        \
    /* ... */                                                                \
private:                                                                     \
    size_t size_;                                                            \
    Type* data_;                                                             \
}

DEFINE_ARRAY(ArrayInt, int);
DEFINE_ARRAY(ArrayFloat, float);

int main() {
    ArrayInt numbers(3);
    ArrayFloat float_numbers(3);
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