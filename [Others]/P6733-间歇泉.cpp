#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

const int MAXN = 1e5;
const double eps = 0.001;

struct Node {
    double a, c;
} g[MAXN + 1];

int n, k;

bool check(double d) {
    double p[n + 1], q[n + 1];
    int res = 0;
    for (int i = 1; i <= n; i++) {
        double x = g[i].a * g[i].c;
        double y = g[i].a * d;
        p[i] = x - y;
        q[i] = y - x;
        if (q[i] - p[i] < eps) res--;
    }
    sort(p + 1, p + n + 1);
    sort(q + 1, q + n + 1);
    int j = 0;
    for (int i = 1; i <= n; i++) {
        while (j < n && q[j + 1] - p[i] < eps) j++;
        res += j;
    }
    return res / 2 < k;
}

int main() {
    ios::sync_with_stdio(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> g[i].a >> g[i].c;
    }
    double l = 1, r = 1e9;
    while (r - l > eps) {
        double mid = (l + r) / 2;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    cout << fixed << setprecision(3) << l;
    return 0;
}
