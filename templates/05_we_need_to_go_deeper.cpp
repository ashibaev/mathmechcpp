template <typename TFirst, typename TSecond>
struct Pair {
    TFirst first;
    TSecond second;
};

int main() {
    Pair<int, float> pair{1, 2.};

    return 0;
}