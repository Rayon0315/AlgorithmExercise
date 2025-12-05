#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

const int INF = 0x7fffffff;
int n, m, s;
vector<int> d, vis;
vector<vector<pair<int, int>>> e;
struct Node {
    int id, dis;

    Node (int I = 0, int D = 0) : id(I), dis(D) {}

    friend bool operator < (const Node ths, const Node oth) {
        return ths.dis > oth.dis;
    }
};

int main() {
    cin >> n >> m >> s;
    e = vector<vector<pair<int, int>>>(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        e[u].push_back({v, w});
    }

    d = vector<int>(n + 1, INF);
    vis = vector<int>(n + 1, 0);
    d[s] = 0;
    priority_queue<Node> Q;
    Q.push(Node(s, 0));
    while (!Q.empty()) {
        int u = Q.top().id; Q.pop();
        if (vis[u]) continue;
        vis[u] = 1;

        for (auto x : e[u]) {
            int v = x.first, w = x.second;
            if (d[v] > d[u] + w) {
                d[v] = d[u] + w;
                Q.push(Node(v, d[v]));
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << d[i] << " ";
    }
    cout << endl;

    return 0;
}