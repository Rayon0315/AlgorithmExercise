#include <iostream>
using namespace std;

void func(int x) {
    if (x == 1) {
        cout << x << " ";
        return;
    }
    if (x & 1) func(3 * x + 1);
    else func(x / 2);
    cout << x << " ";
}

int main() {
    int x; cin >> x;
    func(x);
    return 0;
}