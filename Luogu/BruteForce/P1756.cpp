#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int n;
vector<int> vis;
vector<int> cur;

void DFS(int step) {
    if (step == n) {
        for (auto x : cur) {
            cout << setw(5) << x;
        }
        cout << endl;
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            vis[i] = 1;
            cur.push_back(i);
            DFS(step + 1);
            vis[i] = 0;
            cur.pop_back();
        }
    }
}

int main() {
    cin >> n;
    vis = vector<int>(n + 1, 0);
    DFS(0);
    return 0;
}