#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
using namespace std;

int n;
vector<vector<string>> rec, tri;

int main() {
    cin >> n;
    rec = vector<vector<string>>(n, vector<string>(n, "00"));
    tri = vector<vector<string>>(n, vector<string>(n, "00"));
    for (int i = 1; i <= n * n; i++) {
        int x = i / n, y = (i % n) - 1;
        if (i % n == 0) {
            x = i / n - 1;
            y = n - 1;
        }
        if (i >= 1 && i <= 9) rec[x][y] = "0" + to_string(i);
        else rec[x][y] = to_string(i);
    }

    int cur = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            if (cur >= 1 && cur <= 9) tri[i][j] = "0" + to_string(cur);
            else tri[i][j] = to_string(cur);
            cur++;
        }
    }

    for (auto v : rec) {
        for (auto x : v) {
            cout << x;
        }
        cout << endl;
    }
    cout << endl;
    
    // for (auto v : tri) {
    //     for (auto x : v) {
    //         cout << x;
    //     }
    //     cout << endl;
    // }
    // cout << endl;    

    for (int i = 0; i < n; i++) {
        for (int j = n - 1; j > 0 && tri[i][j] == "00"; j--) {
            cout << "  ";
        }
        for (int j = 0; j < n && tri[i][j] != "00"; j++) {
            cout << tri[i][j];
        }
        cout << endl;
    }
}