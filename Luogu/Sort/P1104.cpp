#include <iostream>
#include <algorithm>
using namespace std;

int n;
struct Student {
    string name;
    int id, y, m, d;

    void init(int i) {
        id = i;
        cin >> name >> y >> m >> d;
    }
} arr[110];

bool cmp(Student A, Student B) {
    if (A.y == B.y) {
        if (A.m == B.m) {
            return (A.d == B.d) ? (A.id > B.id) : (A.d < B.d);
        } else {
            return A.m < B.m;
        }
    } else {
        return A.y < B.y;
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        arr[i].init(i);
    }
    sort(arr + 1, arr + 1 + n, cmp);
    for (int i = 1; i <= n; i++) {
        cout << arr[i].name << endl;
    }
    return 0;
}