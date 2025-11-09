#include <iostream>
#include <string>
using namespace std;

int n;
string cur, inp;

int main() {
    cin >> cur;
    n = cur.size();
    inp = cur;
    for (int i = 0; i < n - 1; i++) {
        cin >> cur;
        inp += cur;
    }
    cout << n << " ";
    int now = 0, cnt = 0;
    for (int i = 0; i < inp.size(); i++) {
        if (inp[i] - '0' != now) {
            cout << cnt << " ";
            cnt = 1;
            now ^= 1;
        } else {
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}