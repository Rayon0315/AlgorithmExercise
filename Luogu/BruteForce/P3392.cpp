#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<vector<char>> mat;

int Draw(int l, int r) {
    int ret = 0;
    for (int i = 0; i <= l; i++) {
        for (int j = 0; j < m; j++) {
            ret += mat[i][j] != 'W';
        }
    }

    for (int i = l + 1; i <= r - 1; i++) {
        for (int j = 0; j < m; j++) {
            ret += mat[i][j] != 'B';
        }
    }

    for (int i = r; i <= n - 1; i++) {
        for (int j = 0; j < m; j++) {
            ret += mat[i][j] != 'R';
        }
    }

    return ret;
}

int main() {
    cin >> n >> m;
    mat = vector<vector<char>>(n, vector<char>(m, '\0'));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat[i][j];
        }
    }

    int ans =  m * n;
    // W: [0, l]  B: [l+1, r-1]  R: [r, n-1]
    for (int l = 0; l < n; l++) {
        for (int r = l + 2; r < n; r++) {
            ans = min(ans, Draw(l, r));
        }
    }

    cout << ans << endl;
    return 0;
}