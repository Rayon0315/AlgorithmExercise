#include <iostream>
#include <vector>
using namespace std;

int n;
vector<vector<int>> mat;

int main() {
    cin >> n;
    mat = vector<vector<int>>(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) 
    for (int j = 0; j < n; j++) {
        cin >> mat[i][j];
    }

    for (int i = 0; i < n; i++)
        mat[i][i] = 1;

    for (int k = 0; k < n; k++)
    for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
        mat[i][j] |= mat[i][k] & mat[k][j];
    }

    cout << "------------------\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    cout << "------------------\n";
    return 0;
}