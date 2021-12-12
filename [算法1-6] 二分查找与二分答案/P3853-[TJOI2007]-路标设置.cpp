#include <iostream>
using namespace std;

const int MAXN = 100000;

int d, n, k, a[MAXN];

bool check(int x) {
    int cnt = 0;
    for (int i = 1; i < n; i++) {
        cnt += (a[i] - a[i - 1]) / x;
        if ((a[i] - a[i - 1]) % x == 0) cnt--;
    }
    return cnt <= k;
}

int main() {
    ios::sync_with_stdio(0);
    cin >> d >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int l = 0, r = d, ans;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check(mid)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << ans;
    return 0;
}
