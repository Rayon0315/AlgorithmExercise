#include <iostream>
#include <map>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

map<string, int> refStoI = {
    {"one", 1}, {"two", 2}, {"three", 3}, {"four", 4}, {"five", 5}, {"six", 6}, {"seven", 7}, {"eight", 8}, {"nine", 9},
    {"ten", 10}, {"eleven", 11}, {"twelve", 12}, {"thirteen", 13}, {"fourteen", 14}, {"fifteen", 15}, {"sixteen", 16}, {"seventeen", 17},
    {"eighteen", 18}, {"nineteen", 19}, {"twenty", 20},
    {"zero", 0}, {"a", 1}, {"both", 2}, {"first", 1}, {"second", 2}, {"third", 3}
};
map<int, string> refItoI = {
    {0, "00"}, {1, "01"}, {2, "04"}, {3, "09"}, {4, "16"}, {5, "25"}, {6, "36"}, {7, "49"}, {8, "64"}, {9, "81"}, {10, "0"}, {11, "21"}, {12, "44"}, {13, "69"}, {14, "96"}, {15, "25"}, {16, "56"}, {17, "89"}, {18, "24"}, {19, "61"}, {20, "00"},
};

bool cmp(string a, string b) {
    return stoi(a) < stoi(b);
}

int main() {
    string s;
    vector<string> vec;
    while (cin >> s) {
        if (s[s.size() - 1] == '.') {
            s = s.substr(0, s.size() - 1);
        }
        transform(s.begin(), s.end(), s.begin(), ::tolower);

        if (refStoI.find(s) != refStoI.end()) {
            string x = refItoI[refStoI[s]];
            vec.push_back(x);
        }


    }

    if (vec.empty()) {
        cout << 0;
        return 0;
    }

    sort(vec.begin(), vec.end(), cmp);

    int cur = 0;
    while (cur < vec.size() && vec[cur] == "00") {
        cur++;
    }
    if (vec[cur][0] == '0') cout << vec[cur++][1];
    for (; cur < vec.size(); cur++) {
        cout << vec[cur];
    }
    return 0;
}