#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    freopen("SuperMario.txt", "w", stdout);
    string s;
    while (getline(cin, s)) {
        cout << "print(\"" << s << "\")\n";
    }
    return 0;
}