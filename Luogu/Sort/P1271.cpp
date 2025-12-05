#include <iostream>
using namespace std;

int n, m;
int buc[1000];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int x; cin >> x;
        buc[x]++;
    }
    for (int i = 1; i <= n; i++) {
        while (buc[i]) {
            cout << i << " ";
            buc[i]--;
        }
    }
    return 0;
}