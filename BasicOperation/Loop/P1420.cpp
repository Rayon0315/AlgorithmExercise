#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> arr;
int ned, crlen, mxlen;

int main() {
    cin >> n;
    arr = vector<int>(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    ned = arr[0], crlen = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == ned) {
            crlen++;
            mxlen = max(mxlen, crlen);
            ned++;
        } else {
            ned = arr[i] + 1;
            crlen = 1;
        }
    }
    cout << mxlen;
    return 0;
}