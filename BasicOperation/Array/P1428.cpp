#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> ado;
vector<int> ans;

int main() {
    cin >> n;
    ado = vector<int>(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> ado[i];
    }
    ans = vector<int>(n, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            ans[i] += (ado[i] > ado[j]);
        }
    }
    for (auto x : ans) {
        cout << x << " ";
    }
    cout << endl;
}