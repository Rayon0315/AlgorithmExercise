#include <iostream>
#include <vector>
using namespace std;

class Matrix {
private:
    int n;
    vector<vector<int>> mat;

public:
    Matrix (int N = 0) : n(N), mat(vector<vector<int>>(n, vector<int>(n, 0))) {}
    Matrix (vector<vector<int>> M) : n(M.size()), mat(M) {}
    
    vector<int>& operator [] (const int &x) {
        return mat[x];
    }

    Matrix subMatrix(int x, int y, int r) {
        Matrix res(2 * r + 1);
        for (int i = x - r; i <= x + r; i++) {
            for (int j = y - r; j <= y + r; j++) {
                res[i - (x - r)][j - (y - r)] = mat[i][j];
            }
        }
        return res;
    }

    void update(int x, int y, int r, Matrix &sub) {
        for (int i = x - r; i <= x + r; i++) {
            for (int j = y - r; j <= y + r; j++) {
                mat[i][j] = sub[i - (x - r)][j - (y - r)];
            }
        }
    }

    Matrix clock() {
        Matrix res(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                res[j][n - i - 1] = mat[i][j];
            }
        }
        return res;
    }
    Matrix antiClock() {
        Matrix res(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                res[n - j - 1][i] = mat[i][j];
            }
        }
        return res;
    }

    friend ostream& operator << (ostream &out, Matrix &A) {
        for (auto v : A.mat) {
            for (auto x : v) {
                out << x << " ";
            }
            out << endl;
        }
        return out;
    }
};

int n, m;

int main() {
    cin >> n >> m;
    Matrix A(n);
    int cur = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            A[i][j] = cur++;
        }
    }

    while (m--) {
        int x, y, r, z;
        cin >> x >> y >> r >> z;
        Matrix sub = A.subMatrix(x - 1, y - 1, r);
        if (z == 0) {
            sub = sub.clock();
            A.update(x - 1, y - 1, r, sub);
        } else {
            sub = sub.antiClock();
            A.update(x - 1, y - 1, r, sub);
        }
        // cout << "----------------------------\n";
        // cout << A;
        // cout << "----------------------------\n\n";
    }
    cout << A;
    return 0;
}