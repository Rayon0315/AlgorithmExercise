#include <iostream>
#include <algorithm>
using namespace std;

int n;
struct Student {
    int id, A, B, C;

    void init(int i) {
        id = i;
        cin >> A >> B >> C;
    }

    int sum() {
        return A + B + C;
    }
} stu[310];

bool cmp(Student& x, Student& y) {
    if (x.sum() == y.sum()) return (x.A == y.A) ? (x.id < y.id) : (x.A > y.A);
    return x.sum() > y.sum();
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) stu[i].init(i);
    sort(stu + 1, stu + n + 1, cmp);
    for (int i = 1; i <= 5; i++) {
        cout << stu[i].id << " " << stu[i].sum() << endl;
    }
    return 0;
}