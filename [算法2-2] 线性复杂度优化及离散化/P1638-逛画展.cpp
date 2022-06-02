#include <iostream>
using namespace std;

const int N = 1e6 + 1;

int n, m, L, R, tot, a[N], cnt[N];

int main() {
    cin.sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int l = 1, r = 1, ans = 0x3f3f3f3f;
    while (r <= n) {
        if (!cnt[a[r]]) tot++;
        cnt[a[r]]++;
        while (cnt[a[l]] > 1) {
            cnt[a[l]]--;
            l++;
        }
        if (tot == m && r - l + 1 < ans) {
            ans = r - l + 1;
            L = l;
            R = r;
        }
        r++;
    }
    cout << L << ' ' << R << endl;
    return 0;
}
