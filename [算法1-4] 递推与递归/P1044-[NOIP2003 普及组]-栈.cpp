#include<iostream>
using namespace std;

int dp[19][19];

int main() {
    int n;
    cin >> n;
    for(int i = 0; i <= n; i++) {
        dp[i][0] = 1;
    }
    for(int j = 1; j <= n; j++) {
        for(int i = 0; i <= n; i++) {
            dp[i][j] = i == 0 ? dp[i + 1][j - 1] : dp[i - 1][j] + dp[i + 1][j - 1];
        }
    }
    cout << dp[0][n];
    return 0;
}
