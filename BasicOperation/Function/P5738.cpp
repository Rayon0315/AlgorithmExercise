#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

int n, m;
vector<double> score;

int main() {
    cin >> n >> m;
    double ans = 0.;
    score = vector<double>(m, 0.);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> score[j];
        }
        double mx = score[0], mn = score[0], sum = 0;
        for (int j = 0; j < m; j++) {
            mx = max(mx, score[j]);
            mn = min(mn, score[j]);
            sum += score[j];
        }
        ans = max(ans, (sum - mx - mn) / (m - 2));
    }

    cout << fixed << setprecision(2) << ans << endl;
    return 0;
}