#include <iostream>
#include <vector>
using namespace std;

int n, d;
vector<int> vis;
vector<vector<int>> g;
int ans = 0;
void DFS(int cur, int cnt) {
    if (cnt > d) return;
    if (cur != 1) ans++;
    vis[cur] = 1;
    for (auto x : g[cur]) {
        if (!vis[x]) DFS(x, cnt + 1);
    }
}

int main() {
    cin >> n >> d;
    vis = vector<int>(n + 1, 0);
    g = vector<vector<int>>(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    DFS(1, 0);
    cout << ans << endl;
    return 0;
}