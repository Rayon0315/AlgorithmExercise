#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
ll n, m;
vector<ll> vec;

bool check(ll cur) {
    ll sum = 0;
    for (auto x : vec) {
        sum += max(0ll, x - cur);
    }
    return sum >= m;
}

int main() {
    cin >> n >> m;
    vec = vector<ll>(n, 0ll);

    ll l = 0, r = 0;
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
        r = max(r, vec[i] + 1);
    }

    ll ans = -1;
    while (l < r) {
        ll mid = l + (r - l) / 2ll;

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