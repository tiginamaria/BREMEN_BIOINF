#include <iostream>
#include <vector>

#include "lib.h"


void get_neighbors_rec(std::string pattern,  std::vector<char> neighbor, int i, int d,
                       std::vector<std::string>& neighbors) {
    if (d < 0) {
        return;
    }

    if (i == pattern.length()) {
        neighbors.push_back(std::string(neighbor.begin(), neighbor.end()));
        return;
    }

    for (char c : LETTERS) {
        neighbor[i] = c;
        get_neighbors_rec(pattern, neighbor, i + 1, d - (pattern[i] == c ? 0 : 1), neighbors);
    }
}

std::vector<std::string> get_neighbors(std::string pattern, int d) {
    std::vector<std::string> neighbors;
    std::vector<char> neighbor(pattern.length());
    get_neighbors_rec(pattern, neighbor, 0, d, neighbors);
    return neighbors;
}

int main(int argc, char **argv) {
    if (argc < 3) {
        std::cout << "Wrong arguments number";
        exit(0);
    }

    std::string pattern = argv[1];
    int d = std::stoi(argv[2]);

    auto neighbors = get_neighbors(pattern, d);

    for (const auto& neighbor : neighbors) {
        std::cout << neighbor << ' ';
    }
}

