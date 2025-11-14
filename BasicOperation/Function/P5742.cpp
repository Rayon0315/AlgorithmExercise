#include <iostream>
#include <vector>
using namespace std;

int n;
class Student {
private:
    int num;
    int A, B;

public:
    Student (int N = 0, int A = 0, int B = 0)
    : num(N), A(A), B(B) {}

    int sum() { return A + B; }
    int tot() { return A * 7 + B * 3; }

    string judge() {
        return (sum() > 140 && tot() >= 800)
            ? "Excellent" : "Not excellent";
    }


    friend istream& operator >> (istream &in, Student &stu) {
        in >> stu.num >> stu.A >> stu.B;
        return in;
    }
};
vector<Student> vec;

int main() {
    cin >> n;
    vec = vector<Student>(n, Student());
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }

    for (int i = 0; i < n; i++) {
        cout << vec[i].judge() << endl;
    }

    return 0;
}