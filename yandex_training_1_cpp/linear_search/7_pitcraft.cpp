// Компьютерная игра происходит в двумерном мире, который состоит из блоков 1 на 1 (метр). 
// Острова игроков - это наборы столбцов различной высоты из блоков (камней). 
// Во время сильных дождей все низины островов заполняются водой. 
// По ландшафта островов, определите объем воды, который накапливается на каждом острове.

#include <iostream>
#include <vector>

using namespace std;


int CalculateTrappedWater(const vector<int>& heights) {
    if (heights.empty()) return 0;

    size_t peak_index = 0;
    for (size_t i = 0; i < heights.size(); i++) {
        if (heights[i] > heights[peak_index]) {
            peak_index = i;
        }
    }

    int trapped_water = 0;

    // Слева до пика
    int left_max = 0;
    for (size_t i = 0; i < peak_index; i++) {
        if (heights[i] > left_max) {
            left_max = heights[i];
        }
        trapped_water += left_max - heights[i];
    }

    // Справа до пика
    int right_max = 0;
    for (size_t i = heights.size() - 1; i > peak_index; i--) {
        if (heights[i] > right_max) {
            right_max = heights[i];
        }
        trapped_water += right_max - heights[i];
    }

    return trapped_water;
}

int CalculateTrappedWaterTwoPointers(const vector<int>& heights) {
    if (heights.empty()) return 0;

    size_t left_pos = 0, right_pos = heights.size() - 1;
    int left_max = heights[left_pos], right_max = heights[right_pos];
    int trapped_water = 0;

    while (left_pos < right_pos) {
        if (left_max >= right_max) {
            trapped_water += right_max - heights[right_pos];
            --right_pos;
            right_max = max(right_max, heights[right_pos]);
        } else {
            trapped_water += left_max - heights[left_pos];
            ++left_pos;
            left_max = max(left_max, heights[left_pos]);
        }
    }
    
    return trapped_water;
}


int main() {
    vector<int> relief_1 = {2, 5, 2, 3, 6, 9, 3, 1, 3, 4, 6}; // 18
    cout << CalculateTrappedWaterTwoPointers(relief_1) << endl;
    vector<int> relief_2 = {1, 2, 3, 4, -11019, 4, 3, 2, 1}; // 11023
    cout << CalculateTrappedWaterTwoPointers(relief_2) << endl;
}