#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int n;
vector<int> num;

int main() {
    cin >> n;
    num = vector<int>(n + 1, 0);
    for (int i = n; i >= 0; i--) cin >> num[i];

    int flag = 0;
    for (int i = n; i >= 0; i--) {
        if (num[i] == 0) continue;
        int a = num[i], absA = abs(a);
        if (flag == 0) {
            if (a < 0) cout << "-";
            if (i == 0) cout << absA;
            else {
                if (absA != 1) cout << absA;
                if (i == 1) cout << "x";
                else cout << "x^" << i;
            }
            flag = 1;
        } else {
            cout << (a > 0 ? "+" : "-");
            if (i == 0) cout << absA;
            else {
                if (absA != 1) cout << absA;
                if (i == 1) cout << "x";
                else cout << "x^" << i;
            }
        }
    }
    return 0;
}
