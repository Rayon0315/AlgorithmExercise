#include <iostream>
using namespace std;

int n, cnt;
int buc[1001];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (!buc[x]) {
            cnt++;
            buc[x] = 1;
        }
    }
    cout << cnt << endl;
    for (int i = 1; i <= 1000; i++) {
        if (buc[i]) cout << i << " ";
    }
    return 0;
}