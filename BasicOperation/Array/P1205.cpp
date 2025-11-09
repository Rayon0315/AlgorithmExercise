#include <iostream>
#include <vector>
using namespace std;

int n;
vector<vector<char>> st, ed;

vector<vector<char>> rot(vector<vector<char>> mat) {
    vector<vector<char>> res(n, vector<char>(n, '_'));
    for (int j = n - 1; j >= 0; j--) {
        for (int i = 0; i < n; i++) {
            res[i][j] = mat[n-j-1][i];
        }
    }
    return res;
}

vector<vector<char>> ref(vector<vector<char>> mat) {
    vector<vector<char>> res = mat;
    for (int i = 0; i < n; i++) {
        for (int j = 0, k = n-1; j <= k; j++, k--) {
            swap(res[i][j], res[i][k]);
        }
    }
    return res;
}

void print(vector<vector<char>> mat) {
    for (auto v : mat) {
        for (auto x : v) {
            cout << x;
        }
        cout << endl;
    }
}

bool situ1() {
    return rot(st) == ed;
}
bool situ2() {
    return rot(rot(st)) == ed;
}
bool situ3() {
    return rot(rot(rot(st))) == ed;
}
bool situ4() {
    return ref(st) == ed;
}
bool situ5() {
    return rot(ref(st)) == ed
           || rot(rot(ref(st))) == ed
           || rot(rot(rot(ref(st)))) == ed;
}
bool situ6() {
    return st == ed;
}


int main() {
    cin >> n;
    st = ed = vector<vector<char>>(n, vector<char>(n, '_'));
    for (auto &v : st) for (auto &x : v) {
        cin >> x;
    }
    for (auto &v : ed) for (auto &x : v) {
        cin >> x;
    }
    if (situ1()) cout << 1;
    else if (situ2()) cout << 2;
    else if (situ3()) cout << 3;
    else if (situ4()) cout << 4;
    else if (situ5()) cout << 5;
    else if (situ6()) cout << 6;
    else cout << 7;
    return 0;
}