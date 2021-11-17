#include<algorithm>
#include <vector>
#include <numeric>


int old_square(int x) {
    return x * x;
}

double old_square(double x) {
    return x * x;
}

template<typename T>
T square(T x) {
    return x * x;
}

int main() {
    int x = old_square(1);
    double y = old_square(1.0);
    // Rational z = old_square(Rational(2, 3));

    int x_new = square(1); // square(1);
    double y_new = square<double>(2.); // square(2.);

    float* m = new float[10];
    std::sort(m, m + 10);

    std::vector<int> v({1, 2, 3});
    std::sort(v.begin(), v.end());

    std::vector<double> vec({1.5, 2.5, 3});
    std::accumulate<std::vector<double>::iterator, double>(vec.begin(), vec.end(), 0);

    return 0;
}