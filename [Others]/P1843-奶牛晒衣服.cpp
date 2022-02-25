#include <iostream>
using namespace std;

const int MAXN = 500000;

int n, a, b, w[MAXN];

bool check(int x) {
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        long long t = w[i] - a * x;
        if (t <= 0) continue;
        sum += t % b ? t / b + 1 : t / b;
    }
    return sum <= x;
}

int main() {
    ios::sync_with_stdio(0);
    cin >> n >> a >> b;
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }
    int l = 1, r = MAXN, ans;
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
