#include <iostream>
#include <vector>
using namespace std;

int r, c, k;
int ans;
vector<vector<char>> mat;

bool checkAcr(int x, int y) {
    if (y + k - 1 >= c) return false;
    for (int i = 0; i < k; i++) {
        if (mat[x][y + i] == '#') return false;
    }
    return true;
}

bool checkVer(int x, int y) {
    if (x + k - 1 >= r) return false;
    for (int i = 0; i < k; i++) {
        if (mat[x + i][y] == '#') return false;
    }
    return true;
}

int main() {
    cin >> r >> c >> k;
    mat = vector<vector<char>>(r, vector<char>(c, '\0'));
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> mat[i][j];
        }
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            ans += checkAcr(i, j) + checkVer(i, j);
        }
    }
    if (k == 1) ans /= 2;
    cout << ans << endl;
    return 0;
}