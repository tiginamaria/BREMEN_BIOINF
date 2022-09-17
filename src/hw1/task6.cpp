#include <iostream>
#include <unordered_map>
#include <vector>


std::vector<int> get_min_skew(const std::string &text) {
    int balance = 0;
    int min_balance = 0;
    std::vector<int> min_balance_pos;
    for (int i = 0; i < text.length(); ++i) {
        if (text[i] == 'C') {
            balance -= 1;
        }
        if (text[i] == 'G') {
            balance += 1;
        }
        if (balance < min_balance) {
            min_balance = balance;
            min_balance_pos.clear();
        }
        if (min_balance == balance) {
            min_balance_pos.push_back(i + 1);
        }
    }
    return min_balance_pos;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cout << "Wrong arguments number";
        exit(0);
    }

    std::string text = argv[1];

    auto min_skew = get_min_skew(text);
    for (const auto &pos: min_skew) {
        std::cout << pos << ' ';
    }
}
