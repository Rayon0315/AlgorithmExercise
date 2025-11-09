#include <iostream>
#include <cmath>
#include <map>
using namespace std;

int n;
int mxl;
double a;
int t;
map<int, int> on;

int main() {
    cin >> n;
    for (int _ = 0; _ < n; _++) {
        cin >> a >> t;
        mxl = max(mxl, (int)floor(a * t));
        for (int i = 1; i <= t; i++) {
            int cur = (int)floor(a * i);
            if (on.find(cur) == on.end()) {
                on[cur] = 1;
            } else {
                on[cur] ^= 1;
            }
        }
    }
    for (int i = 1; i <= mxl; i++) {
        if (on.find(i) != on.end() && on[i]) {
            cout << i;
            break;
        }
    }
    return 0;
}