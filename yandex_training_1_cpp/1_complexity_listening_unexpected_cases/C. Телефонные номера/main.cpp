#include <iostream>  
#include <string>
#include <vector>
#include <algorithm>
#include <ranges>

using namespace std;
using namespace ranges;

// Компактнее через set + algorithms
// Вариант с использованием isdigit
void NormalizeOne(string& number) {
    string normalize_number;
    string to_remove = "+-()"s;

    for (const char& n: number) {
        bool is_remove = false;
        for (const char& c: to_remove) {
            if (n == c) {
                is_remove = true;
                break;
            }
        }
        if (!is_remove) normalize_number += n;
    }

    if (normalize_number.size() == 7) {
        number = "8495" + normalize_number;
    } else if (normalize_number[0] == '7') {
            normalize_number[0] = '8'; // заменяем '7' на '8'
            number = normalize_number;
    } else {
        number = normalize_number;
    }
}


void NormalizeTwo(string& number) {
    erase_if(number, [](char c) {
        return !isdigit(c);
    });

    if (number.size() == 7) {
        number = "8495" + number;
    } else if (number[0] == '7') {
        number[0] = '8';
    }
}


int main() {
    vector<string> numbers(4);
    for (auto& s : numbers) cin >> s, NormalizeTwo(s);
    // for (int i = 1; i < 4; ++i) cout << (numbers[0] == numbers[i] ? "YES\n" : "NO\n");
    for (auto&& s : numbers | views::drop(1)) cout << (s == numbers[0] ? "YES\n" : "NO\n");
}
