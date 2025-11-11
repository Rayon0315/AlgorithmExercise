#include <iostream>
#include <string>
using namespace std;

int q, op;
string doc = "";

void ADD() {
    string tmp;
    cin >> tmp;
    doc += tmp;
    cout << doc << endl;
}

void EXTRACT() {
    int a, b;
    cin >> a >> b;
    doc = doc.substr(a, b);
    cout << doc << endl;
}

void INSERT() {
    int a; string s;
    cin >> a >> s;
    doc = doc.insert(a, s);
    cout << doc << endl;
}

void SEARCH() {
    string s; cin >> s;
    int res = doc.find(s);
    if (res == string::npos) {
        cout << -1 << endl;
    } else {
        cout << res << endl;
    }
}

int main() {
    cin >> q >> doc;
    while (q--) {
        cin >> op;
        switch (op) {
            case 1: ADD(); break;
            case 2: EXTRACT(); break;
            case 3: INSERT(); break;
            case 4: SEARCH(); break;
        }
    }
    return 0;
}