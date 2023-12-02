/*
 * Compile using gcc
 * 
 * $ g++ ./second.cpp -o second.out
 * 
 * Run directly
 * 
 * $ cat input.txt | time ./cpp/second.out
 */

#include <iostream>
#include <string>
#include <string_view>
#include <utility>

constexpr std::pair<std::string_view, int> mappings[19] = {
    {"0", 0},
    {"1", 1},
    {"2", 2},
    {"3", 3},
    {"4", 4},
    {"5", 5},
    {"6", 6},
    {"7", 7},
    {"8", 8},
    {"9", 9},
    {"one", 1},
    {"two", 2},
    {"three", 3},
    {"four", 4},
    {"five", 5},
    {"six", 6},
    {"seven", 7},
    {"eight", 8},
    {"nine", 9},
};

int main() {
    std::string s;
    int n;
    while (true) {
        std::getline(std::cin, s);
        std::string_view sv(s);
        for (int i = 0; i < sv.size(); i++) {
            std::string_view subsv = sv.substr(i);
            for (int j = 0; j < sizeof mappings / sizeof mappings[0]; j++) {
                auto [matchstr, num] = mappings[j];
                if (matchstr.size() > subsv.size()) continue;
                std::string_view matchsubsv = subsv.substr(0, matchstr.size());
                if (matchsubsv == matchstr) {
                    n += num * 10;
                    goto second;
                }
            }
        }
        break;
    second:
        for (int i = s.size(); i > 0; i--) {
            std::string_view subsv = sv.substr(i - 1);
            for (int j = 0; j < sizeof mappings / sizeof mappings[0]; j++) {
                auto [matchstr, num] = mappings[j];
                if (matchstr.size() > subsv.size()) continue;
                std::string_view matchsubsv = subsv.substr(0, matchstr.size());
                if (matchsubsv == matchstr) {
                    n += num;
                    goto next;
                }
            }
        }
        break;
    next:
        s.clear();
    }
    std::cout << n << std::endl;
}