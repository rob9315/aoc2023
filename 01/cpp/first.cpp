/*
 * Compile using gcc
 * 
 * $ g++ ./first.cpp -o first.out
 * 
 * Run directly
 * 
 * $ cat input.txt | time ./cpp/first.out
 */

#include <iostream>
#include <string>

int main() {
    std::string s;
    int n;
    while (true) {
        std::getline(std::cin, s);
        for (int i = 0; i < s.size(); i++) {
            char c = s.at(i);
            if ('0' <= c && c <= '9') {
                n += (c - '0') * 10;
                goto second;
            }
        }
        break;
    second:
        for (int i = s.size(); i > 0; i--) {
            char c = s.at(i - 1);
            if ('0' <= c && c <= '9') {
                n += c - '0';
                s.clear();
                goto next;
            }
        }
        break;
    next:
        continue;
    }
    std::cout << n << std::endl;
}