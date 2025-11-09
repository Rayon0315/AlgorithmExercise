#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
using namespace std;

int n;
vector<int> arr;
double ans;

int main() {
    cin >> n;
    arr = vector<int>(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    for (int i = 1; i < n-1; i++) {
        ans += arr[i];
    }
    ans /= double(n-2);
    cout << fixed << setprecision(2) << ans;
    return 0;
}