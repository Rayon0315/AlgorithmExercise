#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int n, m;
struct Member {
    int id, score;
    
    friend istream& operator >> (istream& in, Member& mem) {
        in >> mem.id >> mem.score;
        return in;
    }
} arr[5050];

bool cmp(Member x, Member y) {
    return (x.score == y.score) ? (x.id < y.id) : (x.score > y.score);
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    sort(arr + 1, arr + 1 + n, cmp);
    int standard = floor((double)m * 1.5);
    int tot = 0;
    int cur = 1;
    while (cur <= n && arr[cur].score >= arr[standard].score) {
        tot++;
        cur++;
    }
    cout << arr[standard].score << " " << tot << endl;
    cur = 1;
    while (cur <= n && arr[cur].score >= arr[standard].score) {
        cout << arr[cur].id << " " << arr[cur].score << endl;
        cur++;
    }
    return 0;
}