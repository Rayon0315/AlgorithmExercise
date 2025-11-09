#include <iostream>
#include <map>
#include <vector>
using namespace std;

const int NUM = 7;
int n;
vector<int> ans(NUM, 0);
vector<int> res(NUM, 0);
map<int, int> fnd;
vector<vector<int>> cur;

int main() {
    cin >> n;
    cur = vector<vector<int>>(n, vector<int>(NUM, 0));

    for (int i = 0; i < NUM; i++) {
        cin >> ans[i];
        fnd[ans[i]] = 1;
    }

    for (int i = 0; i < n; i++)
    for (int j = 0; j < NUM; j++) {
        cin >> cur[i][j];
    }

    for (auto v : cur) {
        int cnt = 0;
        for (auto x : v) {
            if (fnd.find(x) != fnd.end()) {
                cnt++;
            }
        }
        res[NUM - cnt]++;
    }
    
    for (auto x : res) {
        cout << x << " ";
    }
    return 0;
}