#include <iostream>
#include <vector>
using namespace std;

int cnt;
vector<int> cur;
vector<vector<int>> ans;

void func(int step, int left) {
    if (step == 10 && left == 0) {
        ans.push_back(cur);
        cnt++;
        return;
    }

    if (left < (10 - step) || left > (10 - step) * 3) {
        return;
    }

    for (int i = 1; i <= 3; i++) {
        cur.push_back(i);
        func(step + 1, left - i);
        cur.pop_back();
    }
}

int main() {
    int n;
    cin >> n;
    if (n < 10 || n > 30) {
        cout << 0 << endl;
        return 0;
    }

    func(0, n);

    cout << cnt << endl;
    for (auto v : ans) {
        for (auto x : v) {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}