#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string str[20];
int use[20], len, n;

int check(string str1, string str2) {
    for (int i = 1; i < (int) min(str1.size(), str2.size()); i++) {
        bool flag = 1;
        for (int j = 0; j < i; j++) {
            if (str1[str1.size() - i + j] != str2[j]) flag = 0;
        }
        if (flag) return i;
    }
    return 0;
}

void solve(string s, int cur) {
    len = max(cur, len);
    for (int i = 0; i < n; i++) {
        if (use[i] >= 2) continue;
        int c = check(s, str[i]);
        if (c > 0) {
            use[i]++;
            solve(str[i], cur + str[i].size() - c);
            use[i]--;
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i <= n; i++) {
        use[i] = 0;
        cin >> str[i];
    }
    solve(' ' + str[n], 1);
    cout << len;
}
