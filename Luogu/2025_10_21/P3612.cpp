#include<iostream>
using namespace std;

string s;
long long n, len, cur;

int main() {
    cin >> s >> n;
    len = s.size();

    while (len < n) {
        cur = len;
        while (n > cur) cur *= 2;
        n -= (cur/2 + 1);
        if (n == 0) n = cur/2;
    }
    cout << s[n - 1];
    return 0;
}