#include <iostream>
#include <vector>
using namespace std;

vector<int> buk(26, 0);

int main() {
    char c;
    while (cin >> c) {
        if (c >= 'A' && c <= 'Z') {
            buk[c - 'A']++;
        }
    }

    int height = 0;
    for (auto x : buk) height = max(height, x);

    for (int i = height; i >= 1; i--) {
        for (int c = 0; c < 26; c++) {
            cout << (buk[c] >= i ? '*' : ' ');
            if (c != 25) cout << ' ';
        }
        cout << endl;
    }

    for (int i = 0; i < 26; i++) {
        cout << char(i + 'A');
        if (c != 25) cout << ' ';
    }
    return 0;
}