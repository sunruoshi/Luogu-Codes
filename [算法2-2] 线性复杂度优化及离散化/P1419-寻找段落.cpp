#include <iostream>
#include <iomanip>
#include <deque>
using namespace std;

const int N = 1e5 + 1;
const double EPS = 1e-5;

int n, s, t;
double a[N], sum[N];

bool check(double x) {
    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + a[i] - x;
    }
    deque<int> q;
    // 对于一个右端点为 i ，左端点为 i - t + 1 到 i - s + 1 的区间都是合法的
    // 找到所有合法的区间中和最大的区间
    // 如果最大区间和大于 0 ，则说明还存在更大的答案。
    // 否则要缩小答案
    for (int i = s; i <= n; i++) {
        while (q.size() && sum[i - s] < sum[q.back()]) q.pop_back();
        q.push_back(i - s);
        while (q.front() < i - t) q.pop_front();
        if (sum[i] - sum[q.front()] > EPS) return 1;
    }
    return 0;
}

int main() {
    cin.sync_with_stdio(0);
    cin >> n >> s >> t;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    double l = -1e4, r = 1e4;
    while (r - l > EPS) {
        double mid = (l + r) / 2;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    cout << fixed << setprecision(3) << l << endl;
    return 0;
}
