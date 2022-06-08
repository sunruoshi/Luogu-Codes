#include <iostream>
#include <iomanip>
#include <deque>
using namespace std;

const int N = 1e5 + 1;

int n, s, t;
double a[N], sum[N];

bool check(double x) {
    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + a[i] - x;
    }
    deque<int> q;
    for (int i = s; i <= n; i++) {
        while (q.size() && sum[i - s] < sum[q.back()]) q.pop_back();
        q.push_back(i - s);
        while (q.front() < i - t) q.pop_front();
        if (sum[i] - sum[q.front()] >= 0) return 1;
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
