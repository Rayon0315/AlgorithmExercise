#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int n, r;
vector<int> cur;

void DFS(int step, int start) {
    if (step == r) {
        for (auto x : cur) {
            cout << setw(3) << x;
        }
        cout << endl;
        return;
    }

    if (n - start + 1 < r - step) return;

    for (int i = start; i <= n; i++) {
        cur.push_back(i);
        DFS(step + 1, i + 1);
        cur.pop_back();
    }
}

int main() {
    cin >> n >> r;
    DFS(0, 1);
    return 0;
}