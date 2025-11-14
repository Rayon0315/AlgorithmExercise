#include <iostream>
using namespace std;

long long sum, mul;

int main() {
    long long inp;
    while (cin >> inp) {
        sum += inp;
        mul++;
    }
    cout << sum * (1 << (mul - 1));
    return 0;
}