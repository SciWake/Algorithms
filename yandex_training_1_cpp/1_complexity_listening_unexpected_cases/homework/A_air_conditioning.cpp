#include <iostream>
#include <string>

int main() {
    int troom, tcond;
    std::string mode;

    std::cin >> troom >> tcond;
    std::cin >> mode;

    int result;

    if (mode == "freeze") {  // Только охлаждение
        result = std::min(troom, tcond);
    } else if (mode == "heat") {  // Только нагрев
        result = std::max(troom, tcond);
    } else if (mode == "auto") {  // Автоматически доводит до нужной температуры
        result = tcond;
    } else if (mode == "fan") {  // Только вентиляция, температура не меняется
        result = troom;
    }

    std::cout << result << std::endl;

    return 0;
}
