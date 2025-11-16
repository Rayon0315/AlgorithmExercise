#include <iostream>
#include <vector>
using namespace std;

int n, m;
int cur;

int toL(int k) {
    int tmp = cur;
    //cout << "[L]cur-before::" << tmp << endl;
    tmp -= k;
    if (tmp < 0) tmp += n;
    //cout << "[L]cur-after::" << tmp << endl;
    return tmp;
}
int toR(int k) {
    int tmp = cur;
    //cout << "[R]cur-before::" << tmp << endl;
    tmp += k;
    if (tmp >= n) tmp -= n;
    //cout << "[R]cur-after::" << tmp << endl;
    return tmp;
}

class Person {
private:
    int ori;
    string name;

public:
    Person (int O = 0, string N = "")
    : ori(O), name(N) {}

    int getOri() { return ori; }
    string getName() { return name; }

    int work(int dict, int k) {
        if (ori == 0) {
            if (dict == 0) return toL(k);
            else return toR(k);
        } else {
            if (dict == 0) return toR(k);
            else return toL(k);
        }
    }

    friend istream& operator >> (istream &in, Person &per) {
        in >> per.ori >> per.name;
        return in;
    }
    friend ostream& operator << (ostream &out, Person &per) {
        out << per.name << "(" << per.ori << ")";
        return out;
    }
};
vector<Person> vec;

void printAll() {
    cout << "------------------\n";
    for (auto ele : vec) {
        cout << ele << " ";
    }
    cout << "\n------------------\n\n";
}

void printOne(int x) {
    cout << "[+]" << vec[x] << endl;
}

int main() {
    cin >> n >> m;
    vec = vector<Person>(n, Person());
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }

    //printAll();

    cur = 0;
    for (int i = 0; i < m; i++) {
        //printOne(cur);

        int a, s;
        cin >> a >> s;
        cur = vec[cur].work(a, s);
    }
    cout << vec[cur].getName();
    return 0;
}