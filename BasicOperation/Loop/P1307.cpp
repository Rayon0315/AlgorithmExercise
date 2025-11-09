#include <iostream>
#include <string>
using namespace std;

int inp;

string rev(string s) {
    for (int i = 0, j = s.size() - 1; i <= j; i++, j--) {
        swap(s[i], s[j]);
    }
    while (s[0] == '0') {
        s.erase(0, 1);
    }
    return s;
}

int main() {
    cin >> inp;
    if (inp == 0) {
        cout << 0;
        return 0;
    }
    if (inp < 0) {
        cout << "-";
        inp = -inp;
    }
    cout << rev(to_string(inp)) << endl;
    return 0;
}