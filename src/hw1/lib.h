#ifndef BREMEN_BIOINF_LIB_H
#define BREMEN_BIOINF_LIB_H

#include <string>
#include <unordered_map>

const char LETTERS[] = {'A', 'T', 'C', 'G'};

std::unordered_map<std::string, int> get_freq_table(const std::string &text, int k) {
    std::unordered_map<std::string, int> freq_table;
    for (auto i = 0; i <= text.length() - k; ++i) {
        freq_table[text.substr(i, k)] += 1;
    }

    return freq_table;
}


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
