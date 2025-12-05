#include <iostream>
#include <algorithm>
using namespace std;

int n;
string arr[50];

// 判断s票数是否比t多
bool judge(string s, string t) {
    if (s.size() != t.size()) return s.size() > t.size();
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != t[i]) return s[i] > t[i];
    }
    return false;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    int res = 1;
    for (int i = 2; i <= n; i++) {
        if (judge(arr[i], arr[res])) {
            res = i;
        }
    }
    cout << res << endl << arr[res];
    return 0;
}