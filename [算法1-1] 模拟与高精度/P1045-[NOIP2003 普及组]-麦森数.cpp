#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

vector<int> mul(vector<int> &A, vector<int> &B) {
    vector<int> res (A.size() + B.size(), 0);
    int t = 0;
    for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j < B.size(); j++) {
            res[i + j] += A[i] * B[j];
        }
    }
    for (int i = 0; i < res.size(); i++) {
        t += res[i];
        res[i] = t % 10;
        t /= 10;
    }
    while (res.size() > 500) res.pop_back();
    return res;
}

vector<int> binpow(vector<int> &A, int P) {
    vector<int> res (1, 1);
    while (P) {
        if (P & 1) res = mul(res, A);
        A = mul(A, A);
        P >>= 1;
    }
    return res;
}

int main() {
    int p;
    cin >> p;
    vector<int> ans (1, 2);
    cout << (int)(log10(2) * p + 1);
    ans = binpow(ans, p);
    while (ans.size() < 500) {
        ans.push_back(0);
    }
    ans[0]--;
    for (int i = 499; i >= 0; i--) {
        if ((499 - i) % 50 == 0) cout << endl;
        cout << ans[i];
    }
    return 0;
}
