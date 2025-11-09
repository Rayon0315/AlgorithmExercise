#include <iostream>
#include <vector>
using namespace std;

int n, m, k;
vector<vector<int>> mat;
vector<vector<int>> torch = {
    {-2, 0},
    {-1, -1}, {-1, 0}, {-1, 1},
    {0, -2}, {0, -1}, {0, 0}, {0, 1}, {0, 2},
    {1, -1}, {1, 0}, {1, 1},
    {2, 0}
};
vector<vector<int>> fluorite = {
    {-2, -2}, {-2, -1}, {-2, 0}, {-2, 1}, {-2, 2},
    {-1, -2}, {-1, -1}, {-1, 0}, {-1, 1}, {-1, 2},
    {0, -2}, {0, -1}, {0, 0}, {0, 1}, {0, 2},
    {1, -2}, {1, -1}, {1, 0}, {1, 1}, {1, 2},
    {2, -2}, {2, -1}, {2, 0}, {2, 1}, {2, 2}
};

bool isLegal(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < n;
}

void addTag(int x, int y) {
    if (isLegal(x, y)) mat[x][y] = 1;
}

int main() {
    cin >> n >> m >> k;
    mat = vector<vector<int>>(n, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        for (auto mov : torch) {
            addTag(x + mov[0], y + mov[1]);
        }
    }
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        for (auto mov : fluorite) {
            addTag(x + mov[0], y + mov[1]);
        }
    }

    // cout << "---------------\n";
    // for (auto v : mat) {
    //     for (auto x : v) {
    //         cout << x;
    //     }
    //     cout << endl;
    // }
    // cout << "---------------\n";

    int ans = 0;
    for (auto v : mat)
    for (auto x : v) {
        ans += (x == 0);
    }
    cout << ans;
    return 0;
}