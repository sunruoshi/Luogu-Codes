#include <iostream>
#include <vector>
using namespace std;

vector<int> mul_int(vector<int> &A, int B) {
    vector<int> res;
    int t = 0;
    for (int i = 0; i < A.size(); i++) {
        t += A[i] * B;
        res.push_back(t % 10);
        t /= 10;
    }
    while (t > 0) {
        res.push_back(t % 10);
        t /= 10;
    }
    return res;
}

int main() {
    int n, m, d;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> m >> d;
        int cnt = 0;
        vector<int> p (1, 1);
        for (int i = 2; i <= m; i++) {
            p = mul_int(p, i);
        }
        for (int i = p.size() - 1; i >= 0; i--) {
            if (p[i] == d) cnt++;
        }
        cout << cnt << endl;
    }
    return 0;
}
