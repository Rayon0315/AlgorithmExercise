#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 2e4 + 10;
int N, B;
int H[MAXN];

bool cmp(int x, int y) {
    return x > y;
}

int main() {
    cin >> N >> B;
    for (int i = 1; i <= N; i++) {
        cin >> H[i];
    }
    sort(H + 1, H + N + 1, cmp);
    int cur = 0;
    for (int i = 1; i <= N; i++) {
        cur += H[i];
        if (cur >= B) {
            cout << i;
            break;
        }
    }
    return 0;
}