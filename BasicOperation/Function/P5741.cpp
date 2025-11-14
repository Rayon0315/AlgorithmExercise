#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int n;
class Student {
private:
    string name;
    int A, B, C;

public:
    Student (string N = "", int A = 0, int B = 0, int C = 0)
        : name(N), A(A), B(B), C(C) {}
    
    int sum() { return A + B + C; }
    string getName() { return name; }

    bool operator == (Student &oth) {
        return abs(A - oth.A) <= 5
            && abs(B - oth.B) <= 5
            && abs(C - oth.C) <= 5
            && abs(sum() - oth.sum()) <= 10;
    }

    friend istream& operator >> (istream &in, Student &stu) {
        in >> stu.name >> stu.A >> stu.B >> stu.C;
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
        for (int j = i + 1; j < n; j++) {
            if (vec[i] == vec[j]) {
                cout << vec[i].getName() << " " << vec[j].getName() << endl;
            }
        }
    }
    return 0;
}