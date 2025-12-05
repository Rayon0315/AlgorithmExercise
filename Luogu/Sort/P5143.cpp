#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cmath>
using namespace std;

int n;
struct Node {
    double x, y, z;

    friend istream& operator >> (istream& in, Node& node) {
        in >> node.x >> node.y >> node.z;
        return in;
    }
} arr[50050];

bool cmp(Node A, Node B) {
    return A.z < B.z;
}
double dis(Node A, Node B) {
    return sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y) + (A.z - B.z) * (A.z - B.z));
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];       
    }
    sort(arr + 1, arr + n + 1, cmp);
    double res = 0.;
    for (int i = 1; i <= n - 1; i++) {
        res += dis(arr[i], arr[i + 1]);
    }
    cout << fixed << setprecision(3) << res << endl;
    return 0;
}