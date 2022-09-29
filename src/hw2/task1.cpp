#include <iostream>
#include <vector>
#include <unordered_set>

std::vector<std::string> motif_enumeration(std::vector<std::string> &dnas, int k, int d) {
    std::unordered_set<std::string> patterns;

    for (auto dna : dnas) {

    }
}

int main(int argc, char **argv) {
    int k, d;
    std::cin >> k >> d;

    std::vector<std::string> dnas;
    std::string dna;

    while (std::getline(std::cin, dna)) {
        dnas.push_back(dna);
    }
}
