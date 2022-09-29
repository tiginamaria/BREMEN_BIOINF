#include <iostream>
#include <vector>

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

void get_neighbors_rec(const std::string &pattern, std::vector<char> &neighbor, int i, int d,
                       std::vector<std::string> &neighbors) {
    if (d < 0) {
        return;
    }

    if (i == pattern.length()) {
        neighbors.emplace_back(neighbor.begin(), neighbor.end());
        return;
    }

    for (char c: LETTERS) {
        neighbor[i] = c;
        get_neighbors_rec(pattern, neighbor, i + 1, d - (pattern[i] == c ? 0 : 1), neighbors);
    }
}

std::vector<std::string> get_neighbors(const std::string &pattern, int d) {
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

    for (const auto &neighbor: neighbors) {
        std::cout << neighbor << ' ';
    }
}
