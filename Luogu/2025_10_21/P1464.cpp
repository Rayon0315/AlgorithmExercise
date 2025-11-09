#include<cstdio>
#include<iostream>
#include<climits>
using namespace std;

#define ll long long

ll f[25][25][25];

ll run(ll a, ll b, ll c) {
    if (a <= 0 || b <= 0 || c <= 0) return 1;
    if (a > 20 || b > 20 || c > 20) return run(20, 20, 20);
    if (f[a][b][c]) return f[a][b][c];
    if (a < b && b < c) return f[a][b][c] = run(a, b, c-1) + run(a, b-1, c-1) - run(a, b-1, c);
    return f[a][b][c] = run(a-1, b, c) + run(a-1, b-1, c) + run(a-1, b, c-1) - run(a-1, b-1, c-1);
}

int main() {
    ll a, b, c;
    while (cin >> a >> b >> c) {
        if (a == -1 && b == -1 && c == -1) return 0;
        printf("w(%lld, %lld, %lld) = %lld\n", a, b, c, run(a, b, c));
    }
    return 0;
}