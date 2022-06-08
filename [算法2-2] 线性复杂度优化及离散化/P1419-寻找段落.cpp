#include <iostream>
#include <iomanip>
#include <deque>
using namespace std;

const int N = 1e5 + 1;

int n, s, t;
double a[N], b[N], sum[N];

bool check(double x) {
    for (int i = 1; i <= n; i++) {
        b[i] = a[i] - x;
    }
    sum[0] = 0;
    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + b[i];
    }
    deque<int> q;
    for (int i = 1; i <= n; i++) {
        if (i >= s) {
            while (q.size() && sum[i - s] < sum[q.back()]) q.pop_back();
            q.push_back(i - s);
        }
        if (q.size() && q.front() < i - t) q.pop_front();
        if (q.size() && sum[i] - sum[q.front()] >= 0) return 1;
    }
    return 0;
}

int main() {
    cin.sync_with_stdio(0);
    cin >> n >> s >> t;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    double l = -1e8, r = 1e8;
    while (r - l > 1e-5) {
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
