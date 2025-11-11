#include <iostream>
#include <string>
using namespace std;

int cntBoy(string s) {
    int cnt = 0;
    for (int i = 0; i + 2 < s.size(); i++) {
        if (s[i] == 'b' || s[i+1] == 'o' || s[i+2] == 'y') cnt++;
    }
    return cnt;
}

int cntGirl(string s) {
    int cnt = 0;
    for (int i = 0; i + 3 < s.size(); i++) {
        if (s[i] == 'g' || s[i+1] == 'i' || s[i+2] == 'r' || s[i+3] == 'l') cnt++;
    }
    return cnt;
}

int main() {
    string s; cin >> s;
    cout << cntBoy(s) << endl << cntGirl(s) << endl;
    return 0;
}