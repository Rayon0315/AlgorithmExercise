#include <iostream>
#include <vector>
#include <climits>
using namespace std;

vector<int> s(4, 0);
vector<vector<int>> mat(4);

int ans, cur;
int l, r;
void DFS(int sub, int step) {
    if (step == s[sub]) {
        cur = min(cur, max(l, r));
        return;
    }

    l += mat[sub][step];
    DFS(sub, step + 1);
    l -= mat[sub][step];

    r += mat[sub][step];
    DFS(sub, step + 1);
    r -= mat[sub][step];
}

int main() {
    for (int i = 0; i < 4; i++) {
        cin >> s[i];
        mat[i] = vector<int>(s[i], 0);
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < s[i]; j++) {
            cin >> mat[i][j];
        }
    }
    for (int i = 0; i < 4; i++) {
        cur = INT_MAX;
        DFS(i, 0);
        ans += cur;
    }

    cout << ans << endl;
    return 0;
}