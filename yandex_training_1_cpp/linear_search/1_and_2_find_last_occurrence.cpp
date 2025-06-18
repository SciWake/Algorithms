// Дана последовательность чисел диной N. 
// Найти последнее (правое/левое) вхождение числа Х в неё или вывести -1, если число Х не встречалось. 

#include <iostream>
#include <vector>

using namespace std;


// Первое левое вхождение, проход с начала
int FindFirstOccurrence(const vector<int>& numbers, int search_number) {
    int search_index = -1;
    for (size_t i = 0; i < numbers.size(); i++) {
        if (numbers[i] == search_number && search_index == -1) {
            search_index = static_cast<int>(i);
        }
    }
    return search_index;
}

// Первое правео вхождение, проход с начала
int FindLastOccurrence(const vector<int>& numbers, int search_number) {
    int search_index = -1;
    for (size_t i = 0; i < numbers.size(); i++) {
        if (numbers[i] == search_number) {
            search_index = static_cast<int>(i);
        }
    }
    return search_index;
}

// Первое правое вхождение, проход с конца
int FindLastOccurrenceReverse(const vector<int>& numbers, int search_number) {
    int search_index = -1;
    for (size_t i = numbers.size() - 1; i >= 0; i--) {
        if (numbers[i] == search_number && search_index == -1) {
            search_index = static_cast<int>(i);
        }
    }
    return search_index;
}


int main() {
    vector<int> numbers = {2, 5, 1, 8, 9, 2, 1, 1};
    cout << "LFindFirstOccurrence: "s << FindFirstOccurrence(numbers, 1) << endl;
    cout << "FindLastOccurrence: "s << FindLastOccurrence(numbers, 1) << endl;
    cout << "FindLastOccurrenceReverse: "s << FindLastOccurrence(numbers, 21) << endl;
}