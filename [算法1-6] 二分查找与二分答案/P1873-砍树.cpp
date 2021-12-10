#include <iostream>
using namespace std;

const int MAXN = 1e6 + 1;

int n, m, h[MAXN];

bool check(int x) {
    long long sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += max(0, h[i] - x);
    }
    return sum < m ? 0 : 1;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }
    int l = 0, r = 1e9, ans;
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
