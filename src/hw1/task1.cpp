#include <iostream>
#include <vector>
#include <unordered_map>

std::unordered_map<std::string, int> get_freq_table(const std::string &text, int k) {
    std::unordered_map<std::string, int> freq_table;
    for (auto i = 0; i <= text.length() - k; ++i) {
        freq_table[text.substr(i, k)] += 1;
    }

    return freq_table;
}


std::vector<std::string> get_most_frequent_words(const std::string &text, int k) {
    auto freq_table = get_freq_table(text, k);

    int max_freq = 0;
    std::vector<std::string> max_freq_words;

    for (const auto &element: freq_table) {
        if (max_freq < element.second) {
            max_freq = element.second;
            max_freq_words.clear();
        }
        if (max_freq == element.second) {
            max_freq_words.push_back(element.first);
        }
    }

    return max_freq_words;
}

int main(int argc, char **argv) {
    if (argc < 3) {
        std::cout << "Wrong arguments number";
        exit(0);
    }

    std::string text = argv[1];
    int k = std::stoi(argv[2]);

    auto most_frequent_words = get_most_frequent_words(text, k);

    for (const auto &word: most_frequent_words) {
        std::cout << word << ' ';
    }
}
