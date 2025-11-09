#include <iostream>
#include <vector>
using namespace std;

int S1, S2, S3;
vector<int> sav;

int main() {
    cin >> S1 >> S2 >> S3;
    sav = vector<int>(S1 + S2 + S3 + 1, 0);
    for (int i = 1; i <= S1; i++)
    for (int j = 1; j <= S2; j++)
    for (int k = 1; k <= S3; k++)
        sav[i + j + k]++;
    
    int ans = 0, mxl = 0;
    for (int i = 0; i <= S1 + S2 + S3; i++) {
        if (mxl < sav[i]) {
            mxl = sav[i];
            ans = i;
        }
    }
    cout << ans;
    return 0;
}