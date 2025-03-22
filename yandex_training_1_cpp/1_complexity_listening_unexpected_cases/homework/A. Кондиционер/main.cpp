#include <iostream>
#include <string>

using namespace std;


int main() {
    int troom, tcond;
    string mode;

    cin >> troom >> tcond;
    cin >> mode;

    int result;

    if (mode == "freeze") {  // Только охлаждение
        result = min(troom, tcond);
    } else if (mode == "heat") {  // Только нагрев
        result = max(troom, tcond);
    } else if (mode == "auto") {  // Автоматически доводит до нужной температуры
        result = tcond;
    } else if (mode == "fan") {  // Только вентиляция, температура не меняется
        result = troom;
    }

    cout << result << endl;

    return 0;
}
