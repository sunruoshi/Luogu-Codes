#include <iostream>
using namespace std;

const int N = 1001;

int n[6], c[6] = {1, 2, 3, 5, 10, 20}, dp[N], ans;

int main() {
    for (int i = 0; i < 6; i++) cin >> n[i];
    dp[0] = 1;
    for (int i = 0; i < 6; i++) {
        for (int j = 1; j <= n[i]; j++) {
            for (int k = 1000; k >= 0; k--) {
                if (dp[k]) dp[k + c[i]] = 1;
            }
        }
    }
    for (int i = 1; i <= 1000; i++) {
        if (dp[i]) ans++;
    }
    cout << "Total=" << ans << endl;
    return 0;
}
