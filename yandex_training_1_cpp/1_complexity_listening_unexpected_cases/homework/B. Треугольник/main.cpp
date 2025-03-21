#include <iostream>
#include <string>

using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    if (a + b > c && a + c > b && c + b > a) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}