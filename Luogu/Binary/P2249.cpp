#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> arr;

int main() {
    ios::sync_with_stdio(0);

    cin >> n >> m;
    arr = vector<int>(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    while (m--) {
        int target;
        cin >> target;

        int l = 0, r = n;
        while (l < r) {
            int mid = l + (r - l) / 2;

            if (arr[mid] >= target) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        if (l == n || arr[l] != target) {
            cout << -1 << " ";
        } else {
            cout << l + 1 << " ";
        }
    }

    return 0;
}