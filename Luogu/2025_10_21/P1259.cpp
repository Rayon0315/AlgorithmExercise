#include<iostream>
using namespace std;

int n;
string s = "";

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) s += "o";
    for (int i = 1; i <= n; i++) s += "*";
    s += "--";

    int l = n - 1, r = s.size() - 2;
    for (int i = 1; i <= n-3; i++) {
        cout << s << endl;

        s[l] = '-'; s[l+1] = '-';
        s[r] = 'o'; s[r+1] = '*';
        cout << s << endl;

        l--, r -= 2;
        s[l+1] = '*', s[l+2] = '*';
        s[r] = '-', s[r+1] = '-';
    }

    cout << "ooo*o**--" + s.substr(9) << endl;
    cout << "o--*o**oo" + s.substr(9) << endl;
    cout << "o*o*o*--o" + s.substr(9) << endl;
    cout << "--o*o*o*o" + s.substr(9) << endl;
    return 0;
}