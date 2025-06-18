// Задача № 1
// Дана строка (в кодировке UTF-8). Найти самый часто встречающийся в ней символ. 
// Если несколько символов встречаются одинаково часто, то можно вывести любой.

#include <iostream>
#include <string>
#include <set>
#include <unordered_map>

using namespace std;

// Вариант 1: Полный перебор (O(n^2))
char FindMostFrequentCharFor(const string& input) {
    int max_frequency = 0;
    char most_frequent_char = '\0';

    for (const char& outer_char : input) {
        int current_frequency = 0;
        for (const char& inner_char : input) {
            if (outer_char == inner_char) {
                ++current_frequency;
            }
        }
        if (current_frequency > max_frequency) {
            max_frequency = current_frequency;
            most_frequent_char = outer_char;
        }
    }

    return most_frequent_char;
}

// Вариант 2: С использованием множества уникальных символов (O(n * log k))
// std::set — это сбалансированное бинарное дерево, вставка каждого элемента стоит O(log k)
// O(n * log k) — из-за построения set
// O(k * n) — подсчёт частот через вложенный цикл

// Если быть точным, общая сложность — это:
// создание множества уникальных символов
// O(n * log k)  
// + 
// поиск частоты для каждого уникального символа
// O(k * n)  
// =
// O(k * n)  // т.к. эта часть больше. Потому что k <= n, и k * n будет доминировать.

char FindMostFrequentCharSet(const string& input) {
    int max_frequency = 0;
    char most_frequent_char = '\0';

    const set<char> unique_chars(input.begin(), input.end());
    for (const char& outer_char : unique_chars) {
        int current_frequency = 0;
        for (const char& inner_char : input) {
            if (outer_char == inner_char) {
                ++current_frequency;
            }
        }
        if (current_frequency > max_frequency) {
            max_frequency = current_frequency;
            most_frequent_char = outer_char;
        }
    }

    return most_frequent_char;
}

// Вариант 3: Эффективный — с использованием хеш-таблицы (O(n))
char FindMostFrequentCharMap(const string& input) {
    unordered_map<char, int> freq_map;

    for (char c : input) {
        ++freq_map[c];
    }

    char most_frequent_char = '\0';
    int max_frequency = 0;

    for (const auto& [c, freq] : freq_map) {
        if (freq > max_frequency) {
            max_frequency = freq;
            most_frequent_char = c;
        }
    }

    return most_frequent_char;
}

int main() {
    string test = "how araeee";

    cout << "Brute Force: " << FindMostFrequentCharFor(test) << endl;
    cout << "Using Set:   " << FindMostFrequentCharSet(test) << endl;
    cout << "Using Map:   " << FindMostFrequentCharMap(test) << endl;

    return 0;
}
