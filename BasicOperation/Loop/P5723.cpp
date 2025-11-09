#include <iostream>
using namespace std;

int L, ans;

bool isPrime(int n) {
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    cin >> L;
    int now = 2;
    while (L >= now) {
        if (isPrime(now)) {
            L -= now;
            cout << now << endl;
            ans++;
        }
        now++;
    }
    cout << ans << endl;
    return 0;
}