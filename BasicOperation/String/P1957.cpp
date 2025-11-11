#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

string ch(char op) {
    switch (op) {
        case 'a': return "+"; break;
        case 'b': return "-"; break;
        case 'c': return "*"; break;
    }
    return "";
}

int calc(char op, int x, int y) {
    switch (op) {
        case 'a': return x + y; break;
        case 'b': return x - y; break;
        case 'c': return x * y; break;
    }
    return -1;
}

void func(char op, int x, int y) {
    string oup = to_string(x) + ch(op) + to_string(y) + "=" + to_string(calc(op, x, y));
    cout << oup << endl << oup.size() << endl;
}

int n;
char op;
string inp, x, y;

int main() {
    cin >> n;
    while (n--) {
        cin >> inp;
        if (inp[0] == 'a' || inp[0] == 'b' || inp[0] == 'c') {
            op = inp[0];
            cin >> x >> y;
        } else {
            x = inp;
            cin >> y;
        }
        func(op, stoi(x), stoi(y));
    }
    return 0;
}