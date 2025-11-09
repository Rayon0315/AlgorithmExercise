#include<iostream>
using namespace std;

const int N = 1000010;
const int P = 10000;

int f[N], g[N];

int main() {
    int n; cin >> n;

    f[0] = 1;
    f[1] = g[1] = 1;

    for (int i = 2; i <= n; i++) {
        f[i] = (f[i-1] + f[i-2] + 2 * g[i-2]) % P;
        g[i] = (f[i-1] + g[i-1]) % P;
    }
    cout << f[n] << endl;
    return 0;
}