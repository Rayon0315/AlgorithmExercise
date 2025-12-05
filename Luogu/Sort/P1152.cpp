#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int n;
int arr[1010];
int buc[1010];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    for (int i = 1; i < n; i++) {
        int x = abs(arr[i] - arr[i + 1]);
        if (x > 1000) continue;
        buc[abs(arr[i] - arr[i + 1])]++;
    }
    int res = 0;
    for (int i = 1; i <= n-1; i++) {
        res += (buc[i] != 0);
    }
    cout << (res == n - 1 ? "Jolly" : "Not jolly") << endl;
    return 0;
}