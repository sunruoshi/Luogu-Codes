#include <bits/stdc++.h>
using namespace std;

string add(string &A, string &B) {
    string res = "";
    int t = 0;
    for (int i = 0; i < A.size() || i < B.size(); i++) {
        if (i < A.size()) t += A[i] - '0';
        if (i < B.size()) t += B[i] - '0';
        res += (t % 10) + '0';
        t /= 10;
    }
    if (t) res += '1';
    return res;
}

int main() {
    string s1, s2, sum;
    cin >> s1 >> s2;
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    sum = add(s1, s2);
    for (int i = sum.size() - 1; i >= 0; i--) {
        cout << sum[i];
    }
    return 0;
}
