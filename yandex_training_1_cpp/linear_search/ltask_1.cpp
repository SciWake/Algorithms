// Дана последовательность чисел диной N. 
// Найти последнее (правое/левое) вхождение числа Х в неё или вывести -1, если число Х не встречалось. 

#include <iostream>
#include <vector>

using namespace std;


// Первое левое вхождение
int left_search(vector<int> numbers, int search_number) {
    int search_index = -1;
    for (size_t i = 0; i < numbers.size(); i++) {
        if (numbers[i] == search_number && search_index == -1) {
            search_index = static_cast<int>(i);
        }
    }
    cout << search_index << endl;
}

// Первое правео вхождение
int right_search(vector<int> numbers, int search_number) {
    int search_index = -1;
    for (size_t i = 0; i < numbers.size(); i++) {
        if (numbers[i] == search_number) {
            search_index = static_cast<int>(i);
        }
    }
    cout << search_index << endl;
}


int main() {
    vector<int> numbers = {2, 5, 1, 8, 9, 2, 1, 1};
    cout << "Left searhc result: "s << left_search(numbers, 1) << endl;
    cout << "Right searhc result: "s << left_search(numbers, 1) << endl;
}