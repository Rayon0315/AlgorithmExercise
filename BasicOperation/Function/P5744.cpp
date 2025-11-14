#include <iostream>
#include <vector>
using namespace std;

class Student {
private:
    string name;
    int age, score;

public:
    Student (string N = "", int A = 0, int S = 0)
    : name(N), age(A), score(S) {}

    void update() {
        age ++;
        score = score / 5 * 6;
        if (score > 600) score = 600;
    }

    friend istream& operator >> (istream &in, Student &stu) {
        in >> stu.name >> stu.age >> stu.score;
        return in;
    }
    friend ostream& operator << (ostream &out, Student &stu) {
        out << stu.name << " " << stu.age << " " << stu.score;
        return out;
    }
};

int main() {
    int n;
    cin >> n;
    vector<Student> vec(n, Student());
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }
    for (int i = 0; i < n; i++) {
        vec[i].update();
    }
    for (int i = 0; i < n; i++) {
        cout << vec[i] << endl;
    }
    return 0;
}