#include <iostream>
#include <vector>
using namespace std;

int L, R;
vector<int> cnt(10, 0);

void func(int x) {
    while (x) {
        cnt[x % 10]++;
        x /= 10;
    }
}

int main() {
    cin >> L >> R;
    for (int i = L; i <= R; i++) {
        func(i);
    }
    for (auto  x : cnt) {
        cout << x << " ";
    }
    return 0;
}