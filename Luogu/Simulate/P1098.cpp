#include <iostream>
#include <vector>
using namespace std;

int type, loop, rev;
string s;
vector<string> res;

const int LOWER = 1, UPPER = 2, DIGIT = 3;
int check(int cur) {
    if (s[cur] >= 'a' && s[cur] <= 'z') return LOWER;
    if (s[cur] >= 'A' && s[cur] <= 'Z') return UPPER;
    if (s[cur] >= '0' && s[cur] <= '9') return DIGIT;
    return 114514;
}

bool isLegal(int cur) {
    return cur - 1 >= 0 && cur + 1 < s.size() && check(cur - 1) == check(cur + 1) && s[cur - 1] < s[cur + 1];
}

char trans(char c) {
    if (type == 1) {
        if (c >= 'A' && c <= 'Z') return c + ('a' - 'A');
        else return c;
    } else {
        if (c >= 'a' && c <= 'z') return c - ('a' - 'A');
        else return c;
    }
}

string genString(int cur) {
    string ret = "";
    for (char i = s[cur - 1] + 1; i < s[cur + 1]; i++) {
        if (type == 3) {
            for (int j = 0; j < loop; j++) {
                ret += '*';
            }
        } else {
            if (i >= '0' && i <= '9') {
                for (int j = 0; j < loop; j++) {
                    ret += i;
                }
            } else {
                for (int j = 0; j < loop; j++) {
                    ret += trans(i);
                }
            }
        }
    }
    if (rev == 2) 
    for (int i = 0, j = ret.size() - 1; i <= j; i++, j--) {
        swap(ret[i], ret[j]);
    }
    return ret;
}

int main() {
    cin >> type >> loop >> rev;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '-' && isLegal(i)) {
            res.push_back(genString(i));
        }
    }
    int cnt = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '-' && isLegal(i)) {
            cout << res[cnt++];
        } else {
            cout << s[i];
        }
    }
    return 0;
}