#include <iostream>
using namespace std;

int N, cnt;

int main() {
    cin >> N;
    cnt = N / 52;

    for (int K = 1; 21 * K <= cnt; K++) {
        if ((cnt - 21 * K) % 7 == 0 && (cnt - 21 * K) / 7 <= 100) {
            int X = (cnt - 21 * K) / 7;
            cout << X << endl;
            cout << K << endl;
            break;
        }
    }
    return 0;
}