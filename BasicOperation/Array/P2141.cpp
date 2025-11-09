#include <iostream>
#include <vector>
#include <set>
using namespace std;

int n;
int ans;
vector<int> arr;
set<int> S;

int main() {
    cin >> n;
    arr = vector<int>(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        S.insert(arr[i]);
    }
    for (int tar = 0; tar < n; tar++) {
        for (int i = 0; i < n; i++) {
            if (i == tar
                || arr[i] * 2 == arr[tar]
                || arr[i] > arr[tar]) continue;
            if (S.find(arr[tar] - arr[i]) != S.end()) {
                ans++;
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}