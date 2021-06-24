#include<iostream>
using namespace std;

int n, dp[1001];

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i / 2; j++) {
            dp[i] += dp[j];
        }
        dp[i]++;
    }
    cout << dp[n];
    return 0;
}
