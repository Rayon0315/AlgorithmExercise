#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

struct Member {
    string name, pos;
    int id, con, rnk;

    Member (string N = "", string P = "", int I = 0, int C = 0, int R = 0)
    : name(N), pos(P), id(I), con(C), rnk(R) {}
};

int n;
int currentId;
vector<Member> vec;

bool cmpContribution(Member x, Member y) {
    if (x.con == y.con) return x.id < y.id;
    return x.con > y.con;
}

vector<string> rnkPos = {
    "null", "BangZhu", "FuBangZhu", "HuFa",
    "ZhangLao", "TangZhu", "JingYing", "BangZhong"
};
map<string, int> posRnk = {
    {"BangZhu", 1}, {"FuBangZhu", 2},
    {"HuFa", 3}, {"ZhangLao", 4},
    {"TangZhu", 5}, {"JingYing", 6},
    {"BangZhong", 7}

};
map<string, int> posNum = {
    {"BangZhu", 1}, {"FuBangZhu", 2},
    {"HuFa", 2}, {"ZhangLao", 4},
    {"TangZhu", 7}, {"JingYing", 25},
    {"BangZhong", 200}
};

bool cmpPosition(Member x, Member y) {
    if (x.pos == y.pos) return (x.rnk == y.rnk) ? (x.id < y.id) : (x.rnk > y.rnk);
    return posRnk[x.pos] < posRnk[y.pos];
}

void arrangePosition(string pos) {
    int cnt = 0, idx = currentId;
    while (cnt < posNum[pos] && idx < n) {
        if (vec[idx].name != "absi2011" && vec[idx].pos != "BangZhu" && vec[idx].pos != "FuBangZhu") {
            vec[idx].pos = pos;
            cnt++;
        }
        idx++;
    }
    currentId = idx;
}

int main() {
    cin >> n;
    vec = vector<Member>(n, Member());
    for (int i = 0; i < n; i++) {
        vec[i].id = i;
        cin >> vec[i].name >> vec[i].pos >> vec[i].con >> vec[i].rnk;
    }

    sort(vec.begin(), vec.end(), cmpContribution);
    arrangePosition("HuFa");
    arrangePosition("ZhangLao");
    arrangePosition("TangZhu");
    arrangePosition("JingYing");
    arrangePosition("BangZhong");

    sort(vec.begin(), vec.end(), cmpPosition);
    for (auto x : vec) {
        cout << x.name << " " << x.pos << " " << x.rnk << endl;
    }

    return 0;
}