#include <iostream>
#include <string>
using namespace std;

int n;
string res = "";

int main() {
    cin >> n;
    int x, cur = 0;
    while (cin >> x) {
        while (x--) {
            res += to_string(cur);
        }
        cur ^= 1;
    }
    for (int i = 0; i < n; i++) {
        cout << res.substr(i * n, n) << endl;
    }
    return 0;
}