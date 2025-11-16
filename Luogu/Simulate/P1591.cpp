#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class BigInt {
private:
    int len;
    vector<int> num;

public:
    BigInt (int L = 0) : len(L) {
        num = vector<int>(len, 0);
    }
    BigInt (string s) {
        len = s.size();
        num = vector<int>(len, 0);
        for (int i = 0; i < len; i++) {
            num[i] = s[len - i - 1] - '0';
        }
    }
    BigInt (vector<int> oth) {
        len = oth.size();
        num = oth;
    }

    int getlen() {
        return len;
    }

    int& operator [] (int x) {
        return num[x];
    }
    const int& operator [] (int x) const {
        return num[x];
    }

    void delFrontZero() {
        while (len >= 1 && num[len - 1] == 0) {
            num.pop_back();
            len--;
        }
    }

    BigInt operator * (const BigInt &oth) {
        BigInt ret(len + oth.len + 1);
        // cout << "[+] ret.len::: " << ret.len << endl;
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < oth.len; j++) {
                // cout << "[-] (lena, lenb)" << "(" << len << ", " << oth.len << ")" << endl;
                // cout << "[+] (i, j)::: " << "(" << i << ", " << j << ")" << endl;
                ret[i + j] += num[i] * oth[j];
            }
        }
        
        for (int i = 0; i < ret.len - 1; i++) {
            ret[i + 1] += ret[i] / 10;
            ret[i] %= 10;
        }

        ret.delFrontZero();
        return ret;
    }

    friend ostream& operator << (ostream& out, BigInt &big) {
        for (int i = 0; i < big.getlen(); i++) {
            out << big[i];
        }
        return out;
    }

};

int main() {
    int T; cin >> T;
    while (T--) {
        int n, a;
        cin >> n >> a;
        BigInt res = BigInt("1");
        for (int i = 2; i <= n; i++) {
            // cout << i << ":::::" << res << endl;
            res = res * BigInt(to_string(i));
        } 

        int cnt = 0;
        for (int i = 0; i < res.getlen(); i++) {
            cnt += res[i] == a;
        }

        cout << cnt << endl;
    }
    return 0;
}