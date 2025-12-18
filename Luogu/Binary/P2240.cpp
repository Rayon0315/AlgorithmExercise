#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
ll n, k;
vector<ll> len;

bool check(ll x) {
    ll res = 0;
    for (auto cur : len) {
        res += cur / x;
    }
    return res >= k;
}

int main() {
    cin >> n >> k;
    len = vector<ll>(n, 0ll);
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> len[i];
        sum += len[i];
    }

    if (sum < k) {
        cout << 0 << endl;
        return 0;
    }

    ll l = 0, r = sum + 1;
    ll ans = 0;
    while (l < r) {
        ll mid = l + (r - l) / 2;

        if (check(mid)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid;
        }
    }

    cout << ans << endl;
    return 0;
}