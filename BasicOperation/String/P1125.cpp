#include <iostream>
#include <vector>
#include <climits>
using namespace std;

string s;
vector<int> buc(26, 0);

bool isPrime(int n) {
    if (n == 1 || n == 0) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main() {
    cin >> s;
    for (auto c : s) {
        buc[c - 'a']++;
    }
    int mx = INT_MIN, mn = INT_MAX;
    for (auto x : buc) {
        if (x) {
            mx = max(mx, x);
            mn = min(mn, x);
        }
    }
    int del = mx - mn;
    if (isPrime(del)) {
        cout << "Lucky Word" << endl << del;
    } else {
        cout << "No Answer" << endl << 0;
    }
    return 0;
}