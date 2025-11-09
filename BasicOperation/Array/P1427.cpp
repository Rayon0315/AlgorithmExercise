#include <iostream>
using namespace std;

void func() {
    int x; cin >> x;
    if (!x) return;
    func();
    cout << x << ' ';
}

int main() {
    func();
    return 0;
}