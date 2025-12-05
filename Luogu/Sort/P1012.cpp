#include <iostream>
#include <algorithm>
using namespace std;

int n;
string arr[25];

bool cmp(string s, string t) {
    return s + t > t + s;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    sort(arr + 1, arr + 1 + n, cmp);
    for (int i = 1; i <= n; i++) cout << arr[i];
    return 0;
}