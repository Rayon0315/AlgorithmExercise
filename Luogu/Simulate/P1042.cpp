#include <iostream>
#include <cmath>
using namespace std;

string str;
int W, L;

bool complete(int req) {
    return (W >= req || L >= req) && abs(W - L) >= 2;
}

void func(int req) {
    W = L = 0;
    int flag = 0;
    for (auto c : str) {
        if (c == 'W') W++;
        else L++;
        if (complete(req)) {
            cout << W << ":" << L << endl;
            W = L = 0;
        }
    }
    cout << W << ":" << L << endl;
}

int main() {
    char c;
    while (cin >> c) {
        if (c == 'E') break;
        str += c;
    }
    func(11);
    cout << endl;
    func(21);
    return 0;
}