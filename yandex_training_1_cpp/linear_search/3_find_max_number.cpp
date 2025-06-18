// Дана последовательность чисел диной N (N > 0). Найти максимальное число в последовательности.

#include <iostream>
#include <vector>

using namespace std;


// Может приводить к копирвоанию, если объект не примитив int, double...
int FindMaxValue(const vector<int>& numbers) {
    int max_number = numbers[0];
    for (size_t i = 1; i < numbers.size(); i++) {
        if (numbers[i] > max_number) {
            max_number = numbers[i];
        }
    }
    return max_number;
}

// Без копирования объектов
size_t FindMaxIndex(const vector<int>& numbers) {
    size_t max_index = 0;
    for (size_t i = 1; i < numbers.size(); i++) {
        if (numbers[i] > numbers[max_index]) {
            max_index = i;
        }
    }
    return max_index;
}


int main() {
    vector<int> numbers = {2, 5, 1, 8, 9, 2, 1, 1};
    cout << "FindMaxNumber: "s << FindMaxValue(numbers) << endl;
    cout << "FindMaxNumberDontCopy: "s << FindMaxIndex(numbers) << endl;
}