#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double a1, b1;
double a2, b2;
double a3, b3;

double dis(double u, double v, double z, double w) {
    return sqrt( pow(u-z, 2) + pow(v-w, 2) );
}

int main() {
    cin >> a1 >> b1;
    cin >> a2 >> b2;
    cin >> a3 >> b3;

    cout << fixed << setprecision(2)
         << dis(a1, b1, a2, b2) + dis(a2, b2, a3, b3) + dis(a3, b3, a1, b1)
         << endl;
    return 0;
}