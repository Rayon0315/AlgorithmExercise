#include <iostream>
using namespace std;

double tar;
double st = 2., scalar = 0.98;
int step;

int main() {
    cin >> tar;
    while (tar >= 0) {
        tar -= st;
        st *= scalar;
        step++;
    }
    cout << step << endl;
    return 0;
}