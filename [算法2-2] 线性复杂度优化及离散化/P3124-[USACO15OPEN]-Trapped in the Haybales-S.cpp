#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

const ll INF = 0x3f3f3f3f3f3f3f3f;
const int N = 1e5 + 1;

int n, b, cur;
ll ans = INF;

struct Node {
    int s, p;
    bool operator < (const Node &x) const {
        return p < x.p;
    }
} a[N];

int main() { 
    cin.sync_with_stdio(0);
    cin >> n >> b;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].s >> a[i].p;
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) {
        if (a[i].p > b) {
            cur = i;
            break;
        }
    }
    ll l = cur - 1, r = cur, d = a[r].p - a[l].p;
    while (l >= 1 && r <= n) {
        if (a[l].s >= d && a[r].s >= d) {
            cout << 0 << endl;
            return 0;
        } else if (a[r].s < d) {
            r++;
            d += a[r].p - a[r - 1].p;
        } else {
            ans = min(ans, d - a[l].s);
            l--;
            d += a[l + 1].p - a[l].p;
        }
    }
    l = cur - 1, r = cur, d = a[r].p - a[l].p;
    while (l >= 1 && r <= n) {
        if (a[l].s >= d && a[r].s >= d) {
            cout << 0 << endl;
            return 0;
        } else if (a[l].s < d) {
            l--;
            d += a[l + 1].p - a[l].p;
        } else {
            ans = min(ans, d - a[r].s);
            r++;
            d += a[r].p - a[r - 1].p;
        }
    }
    cout << (ans == INF ? -1 : ans) << endl;
    return 0;
}
