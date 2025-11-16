#include <iostream>
#include <vector>
using namespace std;

class BigInt {
private:
    int len;
    vector<int> num;

public:
    BigInt(int L = 0) : len(L), num(L, 0) {}

    BigInt(string s) {
        len = s.size();
        num = vector<int>(len, 0);
        for (int i = 0; i < len; i++)
            num[i] = s[len - i - 1] - '0';
    }

    int getlen() const {
        return len;
    }

    int& operator [] (int x) { return num[x]; }
    const int& operator [] (int x) const { return num[x]; }

    void norm() {
        while (len > 1 && num[len - 1] == 0) {
            num.pop_back();
            len--;
        }
    }

    BigInt operator * (int x) const {
        BigInt ret(len + 5);
        long long c = 0;
        for (int i = 0; i < len; i++) {
            c += 1LL * num[i] * x;
            ret[i] = c % 10;
            c /= 10;
        }
        int p = len;
        while (c) {
            ret[p++] = c % 10;
            c /= 10;
        }
        ret.len = p;
        ret.norm();
        return ret;
    }

    friend ostream& operator << (ostream& out, const BigInt &A) {
        for (int i = A.len - 1; i >= 0; i--)
            out << A[i];
        return out;
    }
};

int main() {
    int n;
    cin >> n;

    if (n == 3) { cout << "3\n3\n"; return 0; }
    if (n == 4) { cout << "4\n4\n"; return 0; }

    vector<int> a;
    int sum = 0;
    for (int x = 2; sum < n; x++) {
        sum += x;
        a.push_back(x);
    }

    if (sum > n + 1) {
        int t = sum - n - 1;
        a[t - 1] = 0;
    }
    else if (sum == n + 1) {
        a.back()++;
        a[0] = 0;
    }

    BigInt res = BigInt("1");
    for (int x : a) {
        if (x == 0) continue;
        cout << x << " ";
        res = res * x;
    }
    cout << "\n";

    cout << res << "\n";

    return 0;
}
