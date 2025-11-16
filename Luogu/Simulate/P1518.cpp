#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

int n = 10;
vector<string> mat(10, "");
vector<vector<int>> mov = {
    {-1, 0}, {0, 1},
    {1, 0}, {0, -1}
};

void printMat() {
    for (auto x : mat) {
        cout << x << endl;
    }
}

struct Object {
    int x, y;
    int dict;

    Object (int X = 0, int Y = 0, int D = 0) : x(X), y(Y), dict(D) {}

    bool isAccessible(int x, int y) {
        return x >= 0 && x < n && y >= 0 && y < n && mat[x][y] != '*';
    }

    void move(int dx, int dy) {
        swap(mat[dx][dy], mat[x][y]);
        x = dx, y = dy;
    }
    void turn() {
        dict ++;
        if (dict == 4) dict = 0;
    }

    void work() {
        // printf("before: (%d, %d), direction:%d\n", x, y, dict);
        int dx = x + mov[dict][0], dy = y + mov[dict][1];
        if (isAccessible(dx, dy)) {
            move(dx, dy);
        } else {
            turn();
        }
        // printMat();
        // printf("after: (%d, %d), direction:%d\n", x, y, dict);
    }

    bool operator == (const Object &oth) {
        return x == oth.x && y == oth.y;
    }
};

int main() {
    // freopen("out.txt", "w", stdout);
    for (int i = 0; i < n; i++) {
        cin >> mat[i];
    }

    Object F, C;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] == 'F') F = Object(i, j, 0);
            if (mat[i][j] == 'C') C = Object(i, j, 0);
        }
    }

    int maxStep = 1e5, curStep = 0;
    while (curStep <= maxStep) {
        // cout << "---------C working----------\n";
        C.work();
        // cout << "----------------------------\n\n";

        // cout << "---------F working----------\n";
        F.work();
        // cout << "---------F working----------\n";

        curStep++;
        if (F == C) {
            cout << curStep << endl;
            return 0;
        }

        // cout << "[+] current steps: " << curStep << endl << endl;
    }
    cout << 0;
    return 0;
}