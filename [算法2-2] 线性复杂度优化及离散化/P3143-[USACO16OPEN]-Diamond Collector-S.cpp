#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e5 + 1;

int n, k, a[N], lmax[N], rmax[N];

int main() {
    cin.sync_with_stdio(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    int l = 1, r = n;
    for (int i = 1; i <= n; i++) {
        while (a[i] - a[l] > k && l <= i) l++;
        lmax[i] = max(lmax[i - 1], i - l + 1);
    }
    for (int i = n; i >= 1; i--) {
        while (a[r] - a[i] > k && r >= i) r--;
        rmax[i] = max(rmax[i + 1], r - i + 1);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, lmax[i] + rmax[i + 1]);
    }
    cout << ans << endl;
    return 0;
}
