#include <iostream>
using namespace std;

int n;
int arr[10010];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int isSwapped = 0;
    int res = 0;
    for (int i = n - 1; i >= 0; i--) {
        isSwapped = 0;
        for (int j = 0; j < i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                isSwapped = 1;
                res++;
            }
        }
        if (!isSwapped) {
            break;
        }
    }
    cout << res << endl;
    return 0;
}