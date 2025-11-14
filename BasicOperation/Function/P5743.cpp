#include <iostream>
using namespace std;

int n;
long long res = 1;

int main() {
    cin >> n;
    n--;
    while (n--) {
        res = (res + 1) * 2;
    }
    cout << res;
    return 0;
}