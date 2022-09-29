#include <iostream>

int get_hamming_distance(const std::string &text1, const std::string &text2) {
    int d = 0;
    for (auto i = 0; i <= text1.size(); ++i) {
        if (text1[i] != text2[i]) {
            d += 1;
        }
    }

    return d;
}

int main(int argc, char **argv) {
    if (argc < 3) {
        std::cout << "Wrong arguments number";
        exit(0);
    }

    std::string text1 = argv[1];
    std::string text2 = argv[2];

    auto hamming_distance = get_hamming_distance(text1, text2);
    std::cout << hamming_distance;
}
