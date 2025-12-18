#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double a, b, c, d;
double calc(double x) {
    return a * x * x * x
         + b * x * x
         + c * x
         + d;
}

const double eps = 1e-3;
double lastAns = -101.;

int main() {
    cin >> a >> b >> c >> d;
    for (double i = -100.; i <= 100.; i = i + 1.) {
        if (calc(i) * calc(i + 1) <= 0.) {
            double l = i, r = i + 1;
            while (r - l >= eps) {
                double mid = l + (r - l) / 2.;
                if (calc(l) * calc(mid) <= 0.) {
                    r = mid;
                } else {
                    l = mid;
                }
            }
            if (fabs(lastAns - l) >= 1.) {
                cout << fixed << setprecision(2) << l << " ";
                lastAns = l;
            }
        }
    }
    return 0;
}