#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t, n, m;
    cin >> t >> n >> m;
    vector<vector<int>> price(t + 1, vector<int>(n + 1));
    for (int i = 1; i <= t; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> price[i][j];
        }
    }
    for (int i = 1; i < t; i++) {
        vector<int> dp(m + 1);
        for (int j = 1; j <= n; j++) {
            for (int k = price[i][j]; k <= m; k++) {
                dp[k] = max(dp[k], dp[k - price[i][j]] + price[i + 1][j] - price[i][j]);
            }
        }
        m += dp[m];
    }
    cout << m << endl;
    return 0;
}
