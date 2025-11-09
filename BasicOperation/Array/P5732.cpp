#include <iostream>
#include <vector>
using namespace std;

int n;
vector<vector<int>> mat;

int main() {
    cin >> n;
    mat = vector<vector<int>>(n, vector<int>(n, 0));
    mat[0][0] = 1;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            mat[i][j] += mat[i-1][j];
            if (j - 1 >= 0) mat[i][j] += mat[i-1][j-1];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}