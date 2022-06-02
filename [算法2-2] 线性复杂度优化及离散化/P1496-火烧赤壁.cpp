#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 20000;

struct Seg {
    int s, t;
} a[MAXN];

int main() {
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i].s >> a[i].t;
    }
    sort(a, a + n, [&](Seg a, Seg b) {return a.s < b.s; });
    int ans = a[0].t - a[0].s, st = a[0].s, ed = a[0].t;
    for (int i = 1; i < n; i++) {
        st = max(a[i].s, ed);
        ed = max(a[i].t, ed);
        ans += ed - st;
    }
    cout << ans;
    return 0;
}
