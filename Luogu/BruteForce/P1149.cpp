#include <iostream>
#include <vector>
using namespace std;

vector<int> unit = {
    6, 2, 5, 5, 4, 5, 6, 3, 7, 6
};
vector<int> cnt(2001, 0);

int main() {
    cnt[0] = unit[0];
    for (int i = 1; i <= 2000; i++) {
        int cur = i;
        while (cur) {
            cnt[i] += unit[cur % 10];
            cur /= 10;
        }
    }

    int n; cin >> n;
    int ans = 0;
    for (int i = 0; i <= 1000; i++) {
        for (int j = 0; j <= 1000; j++) {
            if (cnt[i] + cnt[j] + cnt[i + j] + 4 == n) {
                ans++;
            }
        }
    }
    cout << ans;

    return 0;
}