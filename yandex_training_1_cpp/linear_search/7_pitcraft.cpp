// Компьютерная игра происходит в двумерном мире, который состоит из блоков 1 на 1 (метр). 
// Острова игроков - это наборы столбцов различной высоты из блоков (камней). 
// Во время сильных дождей все низины островов заполняются водой. 
// По ландшафта островов, определите объем воды, который накапливается на каждом острове.

#include <iostream>
#include <vector>

using namespace std;

int CalculateTrappedWater(const vector<int>& relief) {
    size_t global_max_pos = 0;
    for (size_t i = 0; i < relief.size(); i++) {
        if (relief[i] > relief[global_max_pos]) {
            global_max_pos = i;
        }
    }

    int count_water = 0;
    // Проход слева до максимума
    int local_max = 0;
    for (size_t i = 0; i < global_max_pos; i++) {
        if (relief[i] > local_max) {
            local_max = relief[i];
        }
        count_water += local_max - relief[i];
    }
    
    // Проход справа до максимума
    local_max = 0;
    for (size_t i = relief.size() - 1; i > global_max_pos; i--) {
        if (relief[i] > local_max) {
            local_max = relief[i];
        }
        count_water += local_max - relief[i];
    }
    return count_water;
}


int main() {
    vector<int> relief_1 = {2, 5, 2, 3, 6, 9, 3, 1, 3, 4, 6}; // 18
    cout << CalculateTrappedWater(relief_1) << endl;
    vector<int> relief_2 = {1, 2, 3, 4, -11019, 4, 3, 2, 1}; // # 11023
    cout << CalculateTrappedWater(relief_2) << endl;
}