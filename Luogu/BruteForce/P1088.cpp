#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
vector<int> cur;

void toNext() {
    int i = n - 2;

    while (i >= 0 && cur[i] >= cur[i + 1]) i--;

    int j = n - 1;
    while (cur[j] <= cur[i]) j--;

    swap(cur[i], cur[j]);

    for (int l = i + 1, r = n - 1; l <= r; l++, r--) {
        swap(cur[l], cur[r]);
    }
}

int main() {
    cin >> n >> m;
    cur = vector<int>(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> cur[i];
    }
    for (int i = 0; i < m; i++) {
        // next_permutation(cur.begin(), cur.end());
        toNext();
    }
    for (int i = 0; i < n; i++) {
        cout << cur[i] << " ";
    }
    cout << endl;
    return 0;
}