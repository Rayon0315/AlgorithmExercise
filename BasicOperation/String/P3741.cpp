#include <iostream>
using namespace std;

char modify(char c) {
    if (c == 'V') return 'K';
    if (c == 'K') return 'V';
    return '\0';
}

string modify(string s, int k) {
    s[k] = modify(s[k]);
    return s;
}

int cnt(string s, int k) {
    if (k != -1) s = modify(s, k);
    int ret = 0;
    for (int i = 0; i < s.size() - 1; i++) {
        ret += (s[i] == 'V' && s[i+1] == 'K');
    }
    return ret;
}

int n;
string s;
int ans;

int main() {
    cin >> n >> s;
    ans = cnt(s, -1);
    for (int i = 0; i < s.size(); i++) {
        ans = max(ans, cnt(s, i));
    }
    cout << ans << endl;
}