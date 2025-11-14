#include <iostream>
#include <vector>
using namespace std;

vector<int> leap;

bool isLeap(int n) {
    return (n % 400 == 0) || (n % 4 == 0 && n % 100 != 0);
}

int main() {
    int L, R;
    cin >> L >> R;
    for (int i = L; i <= R; i++) {
        if (isLeap(i)) {
            leap.push_back(i);
        }
    }

    cout << leap.size() << endl;
    for (auto y : leap) cout << y << " ";
    return 0;
}