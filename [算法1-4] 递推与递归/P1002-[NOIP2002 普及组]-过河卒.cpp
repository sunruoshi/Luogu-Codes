#include <iostream>
#include <cmath>
using namespace std;

int ban[23][23];
long long dp[23][23];

int main() {
    int n, m, hx, hy, dirs[9][2] = {{0, 0}, {2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};
    cin >> n >> m >> hx >> hy;
    for (int i = 0; i < 9; i++) {
        int dx = hx + 2 + dirs[i][0], dy = hy + 2 + dirs[i][1];
        ban[dx][dy]++;
    }
    dp[2][2] = 1;
    for (int i = 2; i <= n + 2; i++) {
        for (int j = 2; j <= m + 2; j++) {
            if (!ban[i][j]) dp[i][j] = max(dp[i][j], dp[i - 1][j] + dp[i][j - 1]);
        }
    }
    cout << dp[n + 2][m + 2];
    return 0;
}
