#include <iostream>
#include <string>
using namespace std;

bool isOddLen(string s) {
    return s.size() & 1;
}

bool isHW(string s) {
    for (int i = 0, j = s.size() - 1; i <= j; i++, j--) {
        if (s[i] != s[j]) return false;
    }
    return true;
}

bool isPrime(int n) {
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    int l, r;
    cin >> l >> r;
    for (int i = l; i <= r; i ++) {
        if (i / 100 > 0 && !isOddLen(to_string(i))) {
            int cnt = 0;
            while (i / 10 != 0) {
                i /= 10;
                cnt++;
            }
            while (cnt--) {
                i *= 10;
            }
            i *= 10;
        }
        if (isHW(to_string(i)) && isPrime(i)) {
            cout << i << endl;
        }
    }
    return 0;
}