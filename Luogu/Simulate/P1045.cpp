#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const int K = 500;

class BigInt {
private:
    int len;
    vector<int> num;

public:
    BigInt(int L = 1) : len(L), num(L, 0) {}

    BigInt(string s) {
        len = s.size();
        num = vector<int>(len, 0);
        for (int i = 0; i < len; i++)
            num[i] = s[len - i - 1] - '0';
        norm();
    }

    int getlen() const { return len; }

    int& operator [] (int x) { return num[x]; }
    const int& operator [] (int x) const { return num[x]; }

    void norm() {
        while (len > 1 && num[len - 1] == 0)
            num.pop_back(), len--;
    }

    BigInt operator * (const BigInt &y) const {
        int L = min(len + y.len, K + 5);
        BigInt r(L);

        for (int i = 0; i < len; i++) {
            if (i >= K) break;
            int carry = 0;
            for (int j = 0; j < y.len && i + j < K; j++) {
                int t = r[i + j] + num[i] * y[j] + carry;
                r[i + j] = t % 10;
                carry = t / 10;
            }
            if (i + y.len < K && carry)
                r[i + y.len] += carry;
        }
        r.norm();
        r.keep(K);
        return r;
    }

    void keep(int k) {
        if (len > k) {
            num.resize(k);
            len = k;
        }
    }

    void minus1() {
        int i = 0;
        while (num[i] == 0) num[i] = 9, i++;
        num[i]--;
        norm();
    }
};

int main() {
    int P;
    cin >> P;

    int digits = (int)(P * log10(2)) + 1;
    cout << digits << "\n";

    BigInt res("1");
    BigInt base("2");

    int p = P;
    while (p) {
        if (p & 1) res = res * base;
        base = base * base;
        p >>= 1;
    }

    res.minus1();

    vector<int> out(K, 0);
    int L = res.getlen();
    for (int i = 0; i < K && i < L; i++)
        out[i] = res[i];

    for (int i = K - 1; i >= 0; ) {
        for (int j = 0; j < 50; j++, i--)
            cout << out[i];
        cout << "\n";
    }

    return 0;
}
