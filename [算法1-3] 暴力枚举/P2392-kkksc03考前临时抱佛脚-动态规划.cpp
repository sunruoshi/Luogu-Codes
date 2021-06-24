#include <iostream>
#include <cmath>
using namespace std;

int ans, s[4];

int main() {
    for (int i = 0; i < 4; i++) {
        cin >> s[i];
    }
    for (int i = 0; i < 4; i++) {
        int sum = 0, temp[s[i]];
        for (int j = 0; j < s[i]; j++) {
            cin >> temp[j];
            sum += temp[j];
        }
        int dp[sum / 2 + 1];
        for (int j = 0; j <= sum / 2; j++) {
            dp[j] = 0;
        }
        for (int j = 0; j < s[i]; j++) {
            for (int k = sum / 2; k >= 0; k--) {
                if (k >= temp[j]) dp[k] = max(dp[k], dp[k - temp[j]] + temp[j]);
            }
        }
        ans += sum - dp[sum / 2];
    }
    cout << ans;
    return 0;
}
