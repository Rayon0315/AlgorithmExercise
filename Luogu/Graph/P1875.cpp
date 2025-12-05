#include <cstdio>
using namespace std;

const int MAXN = 3000 + 5;
const int MAXM = 6000 + 5;

int n;
long long cost[MAXN], ans[MAXN];
bool vis[MAXN];

int A[MAXM], B[MAXM], C[MAXM];
int m = 0;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &cost[i]);
        ans[i] = 1;  // 初始为直接购买
    }

    int a, b, c;
    while (scanf("%d%d%d", &a, &b, &c) == 3) {
        A[m] = a;
        B[m] = b;
        C[m] = c;
        m++;
    }

    // Dijkstra
    for (int t = 0; t < n; t++) {

        long long mn = 1e18;
        int u = -1;
        for (int i = 0; i < n; i++)
            if (!vis[i] && cost[i] < mn)
                mn = cost[i], u = i;

        if (u == -1) break;
        vis[u] = 1;

        // 尝试所有配方
        for (int i = 0; i < m; i++) {
            int a = A[i], b = B[i], c = C[i];

            // 两种原料必须都确定
            if (vis[a] && vis[b]) {
                long long sum = cost[a] + cost[b];

                if (sum < cost[c]) {
                    cost[c] = sum;
                    ans[c] = ans[a] * ans[b];
                }
                else if (sum == cost[c]) {
                    ans[c] += ans[a] * ans[b];
                }
            }
        }
    }

    printf("%lld %lld\n", cost[0], ans[0]);
    return 0;
}
