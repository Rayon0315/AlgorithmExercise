#include <iostream>
#include <vector>
using namespace std;

int n;
vector<vector<int>> mat;

void func(int siz, int Lx, int Ly, int Rx, int Ry) {
    if (siz == 1) {
        mat[Lx][Ry] = mat[Rx][Ly] = mat[Rx][Ry] = 1;
        return;
    }
    func(siz - 1, Lx, Ly + (1 << (siz - 1)), Rx - (1 << (siz - 1)), Ry);
    func(siz - 1, Lx + (1 << (siz - 1)), Ly, Rx, Ry - (1 << (siz - 1)));
    func(siz - 1, Lx + (1 << (siz - 1)), Ly + (1 << (siz - 1)), Rx, Ry);
}

int main() {
    cin >> n;
    mat = vector<vector<int>>(1 << n, vector<int>(1 << n, 0));
    func(n, 0, 0, (1 << n) - 1, (1 << n) - 1);
    for (auto v : mat) {
        for (auto x : v) {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}