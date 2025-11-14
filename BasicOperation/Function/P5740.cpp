#include <iostream>
#include <vector>
using namespace std;

class Student {
private:
    string name;
    int A, B, C;

public:
    Student (string N = "", int A = 0, int B = 0, int C = 0)
        : name(N), A(A), B(B), C(C) {}
    
    int sum() {
        return A + B + C;
    }

    friend istream& operator >> (istream &in, Student &stu) {
        in >> stu.name >> stu.A >> stu.B >> stu.C;
        return in;
    }

    friend ostream& operator << (ostream &out, Student &stu) {
        out << stu.name << " " << stu.A << " " << stu.B << " " << stu.C;
        return out;
    }
};

vector<Student> vec;

int main() {
    int n; cin >> n;
    vec = vector<Student>(n, Student());
    for (int i = 0; i < n; i++) cin >> vec[i];

    Student res = vec[0];
    for (int i = 0; i < n; i++) {
        if (res.sum() < vec[i].sum()) {
            res = vec[i];
        }
    }

    cout << res;
    return 0;
}