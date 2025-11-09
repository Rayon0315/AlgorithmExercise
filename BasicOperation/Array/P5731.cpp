#include <iostream>
#include <vector>
#include <functional>
#include <cstdio>
#include <iomanip>
using namespace std;

int n;
vector<vector<int>> mat;
int cur = 1, dir;
int x, y;

void func0() {
    // L -> R
    while (y < n && !mat[x][y]) {
        mat[x][y++] = cur++;
    }
    if (y == n) y = n - 1;
    else if (mat[x][y]) y--;
    x++;
}
void func1() {
    // U -> D
    while (x < n && !mat[x][y]) {
        mat[x++][y] = cur++;
    }
    if (x == n) x = n-1;
    else if (mat[x][y]) x--;
    y--;
}
void func2() {
    // R -> L
    while (y >= 0 && !mat[x][y]) {
        mat[x][y--] = cur++;
    }
    if (y == -1) y = 0;
    else if (mat[x][y]) y++;
    x--;
}
void func3() {
    // D -> U
    while (x >= 0 && !mat[x][y]) {
        mat[x--][y] = cur++;
    }
    if (x == -1) x = 0;
    else if (mat[x][y]) x++;
    y++;
}

vector<function<void()>> func = {func0, func1, func2, func3};

void print() {
    cout << "--------------\n";
    for (auto v : mat) {
        for (auto x : v) {
            cout << x << " ";
        }
        cout << endl;
    }
    cout << "--------------\n";
}

int main() {
    cin >> n;
    mat = vector<vector<int>>(n, vector<int>(n, 0));
    for (int i = 0; cur <= n * n; i = (i + 1) % 4) {
        // printf("before:(%d, %d)\n", x, y);

        func[i]();

        // print();
        // printf("now:(%d, %d)\n\n", x, y);
    }
    for (auto v : mat) {
        for (auto x : v) {
            cout << setw(3) << setfill(' ') << x;
        }
        cout << endl;
    }
    return 0;
}