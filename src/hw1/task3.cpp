#include <iostream>

#include "lib.h"

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
