#include <iostream>
#include <vector>
using namespace std;

int A, B, C;
vector<int> vis(10, 0);
vector<int> cur;
int flag = 0;

void check() {
    int X = cur[0] * 100 + cur[1] * 10 + cur[2];
    int Y = cur[3] * 100 + cur[4] * 10 + cur[5];
    int Z = cur[6] * 100 + cur[7] * 10 + cur[8];

    if (X * B - Y * A == 0 && Y * C - Z * B == 0 && Z * A - X * C == 0) {
        flag = 1;
        cout << X << " " << Y << " " << Z << endl;
    }
}

void DFS(int step) {
    if (step == 10) {
        check();
        return;
    }
    for (int i = 1; i <= 9; i++) {
        if (!vis[i]) {
            cur.push_back(i);
            vis[i] = 1;
            DFS(step + 1);
            cur.pop_back();
            vis[i] = 0;
        }
    }
}

int main() {
    cin >> A >> B >> C;
    DFS(1);
    if (!flag) cout << "No!!!" << endl;
    return 0;
}