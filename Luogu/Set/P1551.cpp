#include <iostream>
using namespace std;

const int N = 5010;
int n, m, p;
int f[N];

int findx(int x) {
    if (f[x] == x) return x;
    return f[x] = findx(f[x]);
}

void merge(int x, int y) {
    f[findx(x)] = findx(y);
}

bool judge(int x, int y) {
    return findx(x) == findx(y);
}

int main() {
    cin >> n >> m >> p;
    for (int i = 1; i <= n; i++) {
        f[i] = i;
    }

    while (m--) {
        int u, v;
        cin >> u >> v;
        merge(u, v);
    }

    while (p--) {
        int u, v;
        cin >> u >> v;
        cout << (judge(u, v) ? "Yes" : "No") << endl;
    }

    
    return 0;
}