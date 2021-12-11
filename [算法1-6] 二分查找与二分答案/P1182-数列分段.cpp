#include <iostream>
using namespace std;

const int MAXN = 100001;

int n, m, l, r, a[MAXN];

bool check(int x) {
    int cnt = 0, sum = 0;
    for (int i = 0; i < n; i++) {
        if (sum + a[i] <= x) {
            sum += a[i];
        } else {
            sum = a[i];
            cnt++;
        }
    }
    return cnt >= m;
}

int main() {
    ios::sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        l = max(l, a[i]);
        r += a[i];
    }
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check(mid)) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << l;
    return 0;
}
