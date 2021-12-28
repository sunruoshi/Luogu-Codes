#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    int n, m, t;
    string s, ans = "";
    cin >> n >> s >> m;
    reverse(s.begin(), s.end());
    int d = 0;
    for (size_t i = 0; i < s.size(); i++) {
        if (s[i] >= '0' && s[i] <= '9') t = s[i] - '0';
        else t = 10 + s[i] - 'A';
        d += t * pow(n, i);
    }
    while (d) {
        int c = d % m;
        d /= m;
        if (c >= 10) ans += char(c - 10 + 'A');
        else ans += char(c + '0');
    }
    reverse(ans.begin(), ans.end());
    cout << ans;
}
