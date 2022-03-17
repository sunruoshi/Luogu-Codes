#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        long long n, s;
        cin >> n >> s;
        int a[n + 1];
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        int l = 1, r = 0, L = 1, R = 0;
        while (l <= n) {
            while (s >= 0 && r < n) {
                s += a[++r];
                if (s >= 0 && r - l > R - L) {
                    L = l;
                    R = r;
                }
            }
            s -= a[l++];
        }
        if (L > R) cout << -1 << endl;
        else cout << L << ' ' << R << endl;
    }
    return 0;
}
