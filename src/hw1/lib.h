#ifndef BREMEN_BIOINF_LIB_H
#define BREMEN_BIOINF_LIB_H

#include <string>

const char LETTERS[] = {'A', 'T', 'C', 'G'};

int get_hamming_distance(const std::string &text1, const std::string &text2) {
    int d = 0;
    for (auto i = 0; i <= text1.size(); ++i) {
        if (text1[i] != text2[i]) {
            d += 1;
        }
    }

    return d;
}

#endif //BREMEN_BIOINF_LIB_H
