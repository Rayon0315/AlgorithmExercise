#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

int n, m;
vector<vector<int>> dict = {
    {-1, -1}, {-1, 0}, {-1, 1},
    {0, -1}, {0, 1},
    {1, -1}, {1, 0}, {1, 1}
};

bool legal(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

int main() {
    cin >> n >> m;
    vector<vector<char>> mat(n, vector<char>(m, '\0'));
    vector<vector<int>> res(n, vector<int>(m, -1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == '?') {
                res[i][j] = 0;
                for (auto d : dict) {
                    int x = i + d[0], y = j + d[1];
                    if (legal(x, y)) {
                        //printf("(%d, %d) ----> (%d, %d)\n", i, j, x, y);
                        res[i][j] += (mat[x][y] == '*');
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (res[i][j] == -1) {
                cout << "*";
            } else {
                cout << res[i][j];
            }
        }
        cout << endl;
    }
    return 0;
}