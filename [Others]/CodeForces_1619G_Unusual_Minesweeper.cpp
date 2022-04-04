#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

const int MAXN = 200000;

int fa[MAXN + 1], t[MAXN + 1];

struct Mine {
    int x, y, id;
    bool operator < (const Mine &a) const {
        return x == a.x ? y < a.y : x < a.x;
    }
} a[MAXN + 1];

int Find(int x) {
    return x == fa[x] ? fa[x] : fa[x] = Find(fa[x]);
}

void Union(int x, int y) {
    int xx = Find(x), yy = Find(y);
    if (xx == yy) return;
    fa[xx] = yy;
    t[yy] = min(t[xx], t[yy]);
}

int main() {
    ios::sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        for (int i = 1; i <= n; i++) {
            cin >> a[i].x >> a[i].y >> t[i];
            a[i].id = fa[i] = i;
        }
        int m = 2;
        while (m--) {
            sort(a + 1, a + n + 1);
            for (int i = 1; i < n; i++) {
                if (a[i].x == a[i + 1].x && a[i + 1].y - a[i].y <= k) Union(a[i].id, a[i + 1].id);
            }
            for (int i = 1; i <= n; i++) {
                swap(a[i].x, a[i].y);
            }
        }
        priority_queue<int> q;
        for (int i = 1; i <= n; i++) {
            if (fa[i] == i) q.push(t[i]);
        }
        int ans = 0;
        q.pop();
        while (q.size() && q.top() > ans) {
            q.pop();
            ans++;
        }
        cout << ans << endl;
    }
    return 0;
}
