#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int n, m, dp[51][3];

int main() {
    int ans = pow(2, 31) - 1;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < 3; j++) {
            dp[i][j] = dp[i - 1][j];
        }
        for (int j = 0; j < m; j++) {
            if (s[j] != 'W') dp[i][0]++;
            if (s[j] != 'B') dp[i][1]++;
            if (s[j] != 'R') dp[i][2]++;
        }
    }
    for (int i = 1; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            ans = min(ans, dp[i][0] + dp[j][1] - dp[i][1] + dp[n][2] - dp[j][2]);
        }
    }
    cout << ans;
    return 0;
}
