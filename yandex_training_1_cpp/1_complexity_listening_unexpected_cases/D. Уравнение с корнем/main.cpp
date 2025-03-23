#include <iostream>
#include <string>

using namespace std;


int main() {
    int a, b, c;
    cin >> a >> b >> c;
    if (a == 0)
        cout << (b == c * c ? "MANY SOLUTIONS" : "NO SOLUTION");
    else if (c < 0 || (c * c - b) % a)
        cout << "NO SOLUTION";
    else
        cout << (c * c - b) / a;
}
