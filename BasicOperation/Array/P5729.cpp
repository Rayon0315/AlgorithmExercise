#include <iostream>
#include <vector>
using namespace std;

int w, x, h;
int q;
int X1, Y1, Z1;
int X2, Y2, Z2;
vector<vector<vector<int>>> mat;

void del() {
    for (int i = X1; i <= X2; i++)
    for (int j = Y1; j <= Y2; j++)
    for (int k = Z1; k <= Z2; k++)
        mat[i][j][k] = 0;
}

int main() {
    cin >> w >> x >> h;
    mat = vector<vector<vector<int>>>(w + 1,
          vector<vector<int>>(x + 1, 
          vector<int>(h + 1, 1)));
    
    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> X1 >> Y1 >> Z1;
        cin >> X2 >> Y2 >> Z2;
        del();
    }

    int ans = 0;
    for (int i = 1; i <= w; i++)
    for (int j = 1; j <= x; j++)
    for (int k = 1; k <= h; k++) {
        ans += (mat[i][j][k] == 1);
    }

    cout << ans << endl;
}