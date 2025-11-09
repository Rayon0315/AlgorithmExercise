#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
using namespace std;

int n;
struct Student {
    int A, B, C, sum;

    Student (int a = 0, int b = 0, int c = 0)
    : A(a), B(b), C(c) {
        sum = A + B + C;
    }

    bool operator == (const Student &oth) const {

        // cout << "--------------\n";
        // printf("LSH = (%d, %d, %d)\n", A, B, C);
        // printf("RSH = (%d, %d, %d)\n", oth.A, oth.B, oth.C);
        // printf("delta = (%d, %d, %d, %d)\n", abs(A - oth.A), abs(B - oth.B), abs(C - oth.C), abs(sum - oth.sum));
        // cout << "--------------\n\n";

        return abs(A - oth.A) <= 5 
            && abs(B - oth.B) <= 5
            && abs(C - oth.C) <= 5
            && abs(sum - oth.sum) <= 10;
    }

    friend istream& operator >> (istream &in, Student& x) {
        in >> x.A >> x.B >> x.C;
        x.sum = x.A + x.B + x.C;
        return in;
    }
};
vector<Student> arr;

int main() {
    cin >> n;
    arr = vector<Student>(n, Student());
    for (int i = 0; i < n; i++) cin >> arr[i];

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            ans += (arr[i] == arr[j]);
        }
    }

    cout << ans << endl;
    return 0;
}