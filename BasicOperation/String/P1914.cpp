#include <iostream>
using namespace std;

int n;
string s;

int main() {
    cin >> n >> s;
    for (auto &c : s) {
        c = (c - 'a' + n) % 26 + 'a';
    }
    cout << s;
    return 0;
}