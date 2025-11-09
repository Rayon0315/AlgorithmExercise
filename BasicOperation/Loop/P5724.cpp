#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> arr;
int mx, mn;

int main() {
    cin >> n;
    arr = vector<int>(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    mx = mn = arr[0];
    for (int i = 1; i < n; i++) {
        if (mx < arr[i]) mx = arr[i];
        if (mn > arr[i]) mn = arr[i];
    }
    cout << mx - mn << endl;
    return 0;
}