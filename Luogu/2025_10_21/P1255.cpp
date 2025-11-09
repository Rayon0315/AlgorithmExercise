#include<iostream>
#include<vector>
using namespace std;

struct Int {
    vector<int> num;
    size_t siz;

    Int () {
        num.clear();
        siz = 0;
    }
    Int (int N) {
        while (N) {
            num.push_back(N % 10);
            N /= 10;
        }
        siz = num.size();
    }

    void deleteFrontZero() {
        while (num[siz-1] == 0 && siz != 1) {
            num.pop_back();
            siz--;
        }
    }

    Int operator + (const Int &A) {
        Int res;
        res.siz = max(siz, A.siz) + 1;
        for (int i = 0; i < res.siz; i++) res.num.push_back(0);
        for (int i = 0; i < res.siz; i++) {
            if (i < siz && i < A.siz) {
                res.num[i] = num[i] + A.num[i];
            } else if (i < siz) {
                res.num[i] = num[i];
            } else if (i < A.siz) {
                res.num[i] = A.num[i];
            }
        }
        for (int i = 0; i < res.siz - 1; i++) {
            res.num[i + 1] += res.num[i] / 10;
            res.num[i] %= 10;
        }
        res.deleteFrontZero();
        return res;
    }

    void print() {
        for (int i = siz-1; i >= 0; i--) {
            cout << num[i];
        }
        cout << endl;
    }
};

int main() {
    int n; cin >> n;
    Int A(1), B(2);
    if (n == 1) {
        cout << 1 << endl;
    } else if (n == 2) {
        cout << 2 << endl;
    } else {
        for (int i = 3; i <= n; i++) {
            Int C = A + B;
            A = B;
            B = C;
        }
        B.print();
    }
}