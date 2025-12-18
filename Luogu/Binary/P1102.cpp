#include <iostream>
#include <vector>
#include <map>
using namespace std;

typedef long long ll;
ll n, c;
vector<ll> arr;
map<ll, ll> cnt;


int main() {
    cin >> n >> c;
    arr = vector<ll>(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (cnt.find(arr[i]) == cnt.end()) {
            cnt[arr[i]] = 1;
        } else {
            cnt[arr[i]]++;
        }
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans += cnt[arr[i] - c];
    }
    cout << ans;
    return 0;
}