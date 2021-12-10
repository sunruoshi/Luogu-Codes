#include <iostream>
using namespace std;

const int MAXN = 100001;

int n, k, wood[MAXN];

bool check(int d) {
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        cnt += wood[i] / d;
    }
    return cnt < k ? 0 : 1;
}

int main() {
    ios::sync_with_stdio(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> wood[i];
    }
    int l = 0, r = 1e8, ans = 0;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (check(mid)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << ans;
    return 0;
}
