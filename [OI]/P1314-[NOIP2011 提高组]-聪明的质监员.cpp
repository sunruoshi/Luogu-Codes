#include <iostream>
#include <cstring>
using namespace std;

const int MAXN = 200001;

int n, m, L[MAXN], R[MAXN], W[MAXN], V[MAXN];
long long s, ans = 1e12, sw[MAXN], sv[MAXN];

void solve(int x) {
    memset(sw, 0, sizeof(sw));
    memset(sv, 0, sizeof(sv));
    for (int i = 1; i <= n; i++) {
        if (W[i] >= x) {
            sw[i] = sw[i - 1] + 1;
            sv[i] = sv[i - 1] + V[i];
        } else {
            sw[i] = sw[i - 1];
            sv[i] = sv[i - 1];
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin >> n >> m >> s;
    for (int i = 1; i <= n; i++) {
        cin >> W[i] >> V[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> L[i] >> R[i];
    }
    int l = 1, r = 1e6;
    while (l <= r) {
        int mid = (l + r) >> 1;
        solve(mid);
        long long sum = 0;
        for (int i = 1; i <= m; i++) {
            sum += (sw[R[i]] - sw[L[i] - 1]) * (sv[R[i]] - sv[L[i] - 1]);
        }
        ans = min(ans, abs(s - sum));
        if (sum > s) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << ans << endl;
    return 0;
}
