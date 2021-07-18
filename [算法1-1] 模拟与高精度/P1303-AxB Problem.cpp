#include <bits/stdc++.h>
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
    while (res.size() > 1 && res.back() == 0) res.pop_back();
    return res;
}

int main() {
    string s1, s2;
    vector<int> a, b, ans;
    cin >> s1 >> s2;
    for (int i = s1.length() - 1; i >= 0; i--) {
        a.push_back(s1[i] - '0');
    }
    for (int i = s2.length() - 1; i >= 0; i--) {
        b.push_back(s2[i] - '0');
    }
    ans = mul(a, b);
    for (int i = ans.size() - 1; i >= 0; i--) {
        cout << ans[i];
    }
    return 0;
}
