#include <iostream>
#include <cstring>
using namespace std;

int n;
int isP[10010];

int isPrime(int n) {
    if (isP[n] != -1) return isP[n];
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return isP[n] = 0;
    }
    return isP[n] = 1;
}

void Print(int sum, int A, int B) {
    cout << sum << "=" << A << "+" << B << endl;
}

int main() {
    cin >> n;
    memset(isP, -1, sizeof(isP));
    isP[1] = isP[0] = 0;
    for (int i = 4; i <= n; i += 2) {
        for (int j = 2; j <= i; j++) {
            if (isPrime(j) && isPrime(i - j)) {
                Print(i, j, i - j);
                break;
            }
        }
    }
    return 0;
}