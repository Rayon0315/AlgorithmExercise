#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

typedef long long ll;
int m, n;
vector<ll> a, b;

int main() {
    cin >> m >> n;

    a = vector<ll>(m, 0);
    b = vector<ll>(n, 0);

    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    ll ans = 0;
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
        auto iter = lower_bound(a.begin(), a.end(), b[i]);
        
        ll best = LONG_LONG_MAX;
        if (iter != a.end()) best = min(best, llabs(*iter - b[i]));
        if (iter != a.begin()) best = min(best, llabs(*(iter - 1) - b[i]));

        ans += best;
    }

    cout << ans << endl;
    return 0;
}