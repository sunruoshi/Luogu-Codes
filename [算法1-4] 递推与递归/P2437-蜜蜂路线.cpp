#include <bits/stdc++.h>
using namespace std;

string add(string A, string B) {
    string res = "";
    int temp = 0;
    for (int i = 0; i < A.size() || i < B.size(); i++) {
        if (i < A.size()) temp += A[i] - '0';
        if (i < B.size()) temp += B[i] - '0';
        res += (temp % 10) + '0';
        temp /= 10;
    }
    if (temp) res += "1";
    return res;
}

int main() {
    int m, n;
    scanf("%d %d", &m, &n);
    string prev2 = "1", prev1 = "1";
    for (int i = 2; i <= n - m; i++) {
        string temp = prev1;
        prev1 = add(prev2, prev1);
        prev2 = temp;
    }
    reverse(prev1.begin(), prev1.end());
    cout << prev1;
    return 0;
}
