#include <iostream>
using namespace std;

typedef long long ll;

ll n, m;

ll Cn_2(ll x) {
    return x * (x - 1) / 2;
}

int main() {
    cin >> n >> m;
    ll tot = Cn_2(n + 1) * Cn_2(m + 1);
    ll sqr = 0;
    for (ll i = 1; i <= min(n, m); i++) {
        sqr += (n - i + 1) * (m - i + 1);
    }
    cout << sqr << " " << tot - sqr << endl;
    return 0;
}