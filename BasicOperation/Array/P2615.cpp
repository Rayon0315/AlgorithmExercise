#include <iostream>
#include <vector>
using namespace std;

int N;
vector<vector<int>> mat;

bool situ1(int x, int y) {
    return x == 0 && y !=  N-1;
}
bool situ2(int x, int y) {
    return y == N-1 && x != 0;
}
bool situ3(int x, int y) {
    return x == 0 && y == N-1;
}
bool situ4(int x, int y) {
    return x != 0 && y != N-1;
}

int main() {
    cin >> N;
    mat = vector<vector<int>>(N, vector<int>(N, 0));

    int cur = 1;
    int x = 0, y = N / 2;
    while (cur <= N * N) {
        mat[x][y] = cur++;
        if (cur == N * N + 1) break;
        if (situ1(x, y)) {
            x = N - 1;
            y = y + 1;
        } else if (situ2(x, y)) {
            y = 0;
            x = x - 1;
        } else if (situ3(x, y)) {
            x = x + 1;
            y = y;
        } else if (situ4(x, y)) {
            if (!mat[x - 1][y + 1]) {
                x = x - 1;
                y = y + 1;
            } else {
                x = x + 1;
                y = y;
            }
        }
    }

    for (auto v : mat) {
        for (auto x : v) {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}