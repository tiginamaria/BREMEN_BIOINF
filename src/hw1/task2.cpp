#include <iostream>
#include <vector>


std::vector<int> get_all_occurrences(const std::string &pattern, const std::string &text) {
    std::vector<int> occurrences;
    auto k = pattern.size();
    for (auto i = 0; i <= text.size() - k; ++i) {
        if (text.substr(i, k) == pattern) {
            occurrences.push_back(i);
        }
    }

    return occurrences;
}

int main(int argc, char **argv) {
    if (argc < 3) {
        std::cout << "Wrong arguments number";
        exit(0);
    }

    std::string pattern = argv[1];
    std::string genome = argv[2];

    auto occurrences = get_all_occurrences(pattern, genome);

    for (const auto &pos: occurrences) {
        std::cout << pos << ' ';
    }
}
