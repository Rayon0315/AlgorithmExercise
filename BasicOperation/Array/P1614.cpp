#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> arr;

int main() {
    cin >> n >> m;
    arr = vector<int>(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int L = 0, R = m-1;
    int ans = 0, tmp = 0;
    for (int i = L; i <= R; i++) {
        tmp += arr[i];
    }
    ans = tmp;
    while (R + 1 < n) {
        tmp -= arr[L++];
        tmp += arr[++R];
        ans = min(tmp, ans);
    }
    cout << ans << endl;
    return 0;
}