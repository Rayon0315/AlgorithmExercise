#include <iostream>
using namespace std;

int toNum(char c) {
    return c - 'A' + 1;
}

int calc(string s) {
    int ans = 1;
    for (auto c : s) {
        ans = ans * toNum(c) % 47;
    }
    return ans;
}

int main() {
    string s, t;
    cin >> s >> t;
    cout << (calc(s) == calc(t) ? "GO" : "STAY") << endl;
    return 0;
}