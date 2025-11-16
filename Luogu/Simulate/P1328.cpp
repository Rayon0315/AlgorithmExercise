#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> mat = {
    {0, -1, +1, +1, -1},
    {+1, 0, -1, +1, -1},
    {-1, +1, 0, -1, +1},
    {-1, -1, +1, 0, +1},
    {+1, +1, -1, -1, 0}
};

class Sequence {
private:
    int T, win;
    vector<int> vec;

public:
    Sequence (int t = 0, int w = 0) : T(t), win(w), vec(vector<int>(t, 0)) {}

    int nxt(int cur) {
        cur++;
        if (cur == T) cur = 0;
        return cur;
    }

    int& operator [] (int x) { return vec[x]; }
    int& getWin() { return win; }

    friend istream& operator >> (istream &in, Sequence &A) {
        A.win = 0;
        for (int i = 0; i < A.T; i++) {
            in >> A[i];
        }
        return in;
    }
};

int n, nA, nB;

int main() {
    cin >> n >> nA >> nB;
    Sequence A(nA), B(nB);
    cin >> A >> B;
    int curA = 0, curB = 0;
    for (int cnt = 0; cnt < n; cnt++) {
        if (mat[A[curA]][B[curB]] == 0) {
            A.getWin() += 0;
            B.getWin() += 0;
        } else if (mat[A[curA]][B[curB]] == 1) {
            A.getWin() += 1;
            B.getWin() += 0;
        } else if (mat[A[curA]][B[curB]] == -1) {
            A.getWin() += 0;
            B.getWin() += 1;
        }
        curA = A.nxt(curA);
        curB = B.nxt(curB);
    }
    cout << A.getWin() << " " << B.getWin();
    return 0;
}