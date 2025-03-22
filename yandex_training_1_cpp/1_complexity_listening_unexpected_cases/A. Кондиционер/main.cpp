#include <iostream>
#include <string>

using namespace std;


int ConditionerOne(int t_room, int t_cond, const string& mode) {
    if (mode == "auto" || (t_room < t_cond && mode == "heat") || (t_room > t_cond && mode == "freeze")) {
        return t_cond;
    }
    return t_room;
}


int ConditionerTwo(int t_room, int t_cond, const string& mode) {
    return mode == "auto" ? t_cond :
           mode == "heat" ? max(t_room, t_cond) :
           mode == "freeze" ? min(t_room, t_cond) :
           t_room;
}


int main() {
    int troom, tcond;
    string mode;

    cin >> troom >> tcond;
    cin >> mode;
    cout << ConditionerTwo(troom, tcond, mode) << endl;
}
