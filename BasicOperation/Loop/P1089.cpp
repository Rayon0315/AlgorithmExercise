#include <iostream>
using namespace std;

int cur;
int budget;
int save;

int main() {
    for (int i = 1; i <= 12; i++) {
        cin >> budget;
        cur += 300;
        if (cur < budget) {
            cout << '-' << i;
            return 0;
        } else {
            cur -= budget;
            save += cur / 100 * 100;
            cur %= 100;
        }
    }
    cout << cur + save / 5 * 6;
    return 0;
}