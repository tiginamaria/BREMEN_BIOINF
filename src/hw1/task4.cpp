#include <iostream>
#include <unordered_map>
#include <vector>
#include "lib.h"

int get_count(const std::string &text, const std::string &pattern, int d) {
    auto k = pattern.length();
    int count = 0;
    for (auto i = 0; i <= text.length() - k; ++i) {
        if (get_hamming_distance(pattern, text.substr(i, k)) <= d) {
            count += 1;
        }
    }
    return count;
}

std::string get_reversed_complement_pattern(const std::string &pattern) {
    std::unordered_map<char, char> map = {{'A', 'T'},
                                          {'T', 'A'},
                                          {'C', 'G'},
                                          {'G', 'C'}};

    auto n = pattern.length();
    char reversed_pattern[n];
    for (auto i = 0; i < n; ++i) {
        reversed_pattern[n - i - 1] = map[pattern[i]];
    }

    return reversed_pattern;
}

std::unordered_map<std::string, int> get_freq_table(const std::string &text, int k, int d) {
    std::unordered_map<std::string, int> freq_table;

    for (auto i = 0; i <= text.length() - k; ++i) {
        auto pattern = text.substr(i, k);
        if (freq_table.find(pattern) == freq_table.end()) {
            freq_table[pattern] = get_count(text, pattern, d);
        }
    }

    return freq_table;
}

std::vector<std::string> get_most_frequent_words(const std::string &text, int k, int d) {
    std::unordered_map<std::string, int> freq_table = get_freq_table(text, k, d);

    int max_freq = 0;
    std::vector<std::string> max_freq_words;

    for (const auto &element: freq_table) {
        auto pattern = element.first;
        auto freq = element.second;

        auto reversed_pattern = get_reversed_complement_pattern(pattern);
        std::reverse(reversed_pattern.begin(), reversed_pattern.end());

        if (pattern != reversed_pattern && freq_table.find(reversed_pattern) != freq_table.end()) {
            freq += freq_table[reversed_pattern];
        }

        if (max_freq < freq) {
            max_freq = freq;
            max_freq_words.clear();
        }
        if (max_freq == freq) {
            max_freq_words.push_back(element.first);
        }
    }

    return max_freq_words;
}

int main(int argc, char **argv) {
    if (argc < 4) {
        std::cout << "Wrong arguments number";
        exit(0);
    }

    std::string text = argv[1];
    int k = std::stoi(argv[2]);
    int d = std::stoi(argv[3]);

    auto most_frequent_words = get_most_frequent_words(text, k, d);

    for (const auto &word: most_frequent_words) {
        std::cout << word << ' ';
    }
}
