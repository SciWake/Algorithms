#include <iostream>
#include <string>

using namespace std;


int ConditionerOne(int t_room, int t_cond, const string& mode) {
    return (mode == "auto") || (mode == "heat" && t_room < t_cond) || (mode == "freeze" && t_room > t_cond)
           ? t_cond : t_room;
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
