#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
ll len, n, m;
vector<ll> d;

bool check(ll x) {
    ll last = 0; 
    int removed = 0;

    for (int i = 0; i < n; i++) {
        if (d[i] - last < x) {
            removed++;
        } else {
            last = d[i]; 
        }
    }

    if (len - last < x) {
        removed++;
    }

    return removed <= m;
}
int main() {
    cin >> len >> n >> m;
    d = vector<ll>(n, 0ll);
    for (int i = 0; i < n; i++) {
        cin >> d[i];
    }

    ll l = 0, r = len;
    ll ans = -1;
    while (l <= r) {
        ll mid = l + (r - l) / 2;

        if (check(mid)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    cout << ans << endl;
    return 0;
}