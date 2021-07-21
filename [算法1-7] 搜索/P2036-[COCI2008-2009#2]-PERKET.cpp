#include <iostream>
#include <cmath>
using namespace std;

int n, ans = 1e9, s[11], b[11];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s[i] >> b[i];
    }
    for (int mask = 0; mask < (1 << n); mask++) {
        int p = 0, temp[11];
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                temp[p++] = i + 1;
            }
        }
        if (p) {
            int ts = 1, tb = 0;
            for (int i = 0; i < p; i++) {
                ts *= s[temp[i]];
                tb += b[temp[i]];
            }
            ans = min(ans, abs(ts - tb));
        }
    }
    cout << ans;
    return 0;
}

