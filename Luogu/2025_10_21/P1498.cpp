#include<iostream>
using namespace std;

char c[1050][2050];

int main() {
    int n, len, k;
    len = 4, k = 1;
    cin >> n;

    for (int i = 0; i < 1024; i++)
    for (int j = 0; j < 2048; j++)
        c[i][j] = ' ';
    
    c[0][0] = c[1][1] = '/';
    c[0][1] = c[0][2] = '_';
    c[0][3] = c[1][2] = '\\';

    while (k < n) {
        for (int i = 0; i < len/2; i++)
        for (int j = 0; j < len; j++)
            c[i + len/2][j + len/2] = c[i][j + len] = c[i][j];
        len *= 2, k++;
    }

    for (int i = len/2 - 1; i >= 0; i--) {
        for (int j = 0; j < len; j++) cout << c[i][j];
        cout << endl;
    }

    return 0;
}