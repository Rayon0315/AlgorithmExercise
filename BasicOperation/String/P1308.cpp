#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

int main() {
    string tar, txt;
    getline(cin, tar);
    getline(cin, txt);
    transform(tar.begin(), tar.end(), tar.begin(), ::tolower);
    transform(txt.begin(), txt.end(), txt.begin(), ::tolower);

    stringstream ss(txt);
    string word;
    int cnt = 0, pos = 0, fst = -1, cur = 0;

    while (ss >> word) {
        while (cur < txt.size() && txt[cur] == ' ') {
            cur++;
        }
        if (word == tar) {
            if (cnt == 0) fst = txt.find(word, cur);
            cnt++;
        }
        cur += word.size();
    }

    if (!cnt) cout << -1;
    else cout << cnt << " " << fst;
    return 0;
}