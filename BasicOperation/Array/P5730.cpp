#include <iostream>
#include <vector>
using namespace std;

vector<vector<string>> show = {
    {
        "XXX",
        "X.X",
        "X.X",
        "X.X",
        "XXX"
    },
    {
        "..X",
        "..X",
        "..X",
        "..X",
        "..X"
    },
    {
        "XXX",
        "..X",
        "XXX",
        "X..",
        "XXX"
    },
    {
        "XXX",
        "..X",
        "XXX",
        "..X",
        "XXX"
    },
    {
        "X.X",
        "X.X",
        "XXX",
        "..X",
        "..X"
    },
    {
        "XXX",
        "X..",
        "XXX",
        "..X",
        "XXX"
    },
    {
        "XXX",
        "X..",
        "XXX",
        "X.X",
        "XXX",
    },
    {
        "XXX",
        "..X",
        "..X",
        "..X",
        "..X"
    },
    {
        "XXX",
        "X.X",
        "XXX",
        "X.X",
        "XXX"
    },
    {
        "XXX",
        "X.X",
        "XXX",
        "..X",
        "XXX"
    }
};

int n;
string s;
vector<string> ans;

int main() {
    cin >> n >> s;
    ans = vector<string>(5, "");
    for (int _ = 0; _ < n; _++) {
        int x = s[_] - '0';
        for (int i = 0; i < 5; i++) {
            ans[i] += show[x][i];
            if (_ != n-1) ans[i] += ".";
        }
    }
    for (auto x : ans) cout << x << endl;
    return 0;
}