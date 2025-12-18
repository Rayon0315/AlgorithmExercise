#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

int n;
int ans = INT_MAX;
vector<int> sr, bt;

void DFS(int cur, int S, int B) {
    if (cur == n) {
        if (S == 1 && B == 0) return;
        ans = min(ans, abs(S - B));
        return;
    }
    DFS(cur + 1, S * sr[cur], B + bt[cur]);
    DFS(cur + 1, S, B);
}

int main() {
    cin >> n;
    sr = vector<int>(n, 0);
    bt = vector<int>(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> sr[i] >> bt[i];
    }
    DFS(0, 1, 0);
    cout << ans << endl;
    return 0;
}