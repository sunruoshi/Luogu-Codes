#include <iostream>
#include <iomanip>
#include <deque>
using namespace std;

const int N = 1e5 + 1;
const double EPS = 1e-5;

int n, s, t;
double a[N], b[N];

bool check(double x) {
    for (int i = 1; i <= n; i++) {
        b[i] = b[i - 1] + a[i] - x;
    }
    deque<int> q;
    // 对于一个右端点为 r ，左端点 l 为 r - t + 1 到 r - s + 1 的区间都是合法的
    // sum(l, r) = b[r] - b[l - 1];
    // 滑动窗口+单调队列求所有合法段落的最大和
    for (int r = s; r <= n; r++) {
        while (q.size() && b[r - s] < b[q.back()]) q.pop_back();
        q.push_back(r - s);
        while (q.front() < r - t) q.pop_front();
        if (b[r] - b[q.front()] > 0) return 1;
    }
    return 0;
}

int main() {
    cin.sync_with_stdio(0);
    cin >> n >> s >> t;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    double l = -1e4, r = 1e4, ans;
    while (r - l > EPS) {
        double mid = (l + r) / 2;
        if (check(mid)) {
            ans = l = mid;
        } else {
            r = mid;
        }
    }
    cout << fixed << setprecision(3) << ans << endl;
    return 0;
}
