#include <iostream>
using namespace std;

const int MAXN = 50002;

int d, n, m, stone[MAXN];

bool check(int x) {
    int cnt = 0, cur = 0;
    for (int i = 1; i <= n + 1; i++) {
        if (stone[i] - stone[cur] < x) cnt++;
        else cur = i;
    }
    return cnt > m ? 0 : 1;
}

int main() {
    ios::sync_with_stdio(0);
    cin >> d >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> stone[i];
    }
    stone[n + 1] = d;
    int l = 1, r = d, ans;
    while (l <= r) {
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
