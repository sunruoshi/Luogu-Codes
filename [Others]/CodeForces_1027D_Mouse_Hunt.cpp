#include <iostream>
using namespace std;

const int MAXN = 2e5;

int n, ans, c[MAXN + 1], a[MAXN + 1], vis[MAXN + 1];

int cost(int to, int s, int res) {
    res = min(res, c[to]);
    return to == s ? res : cost(a[to], s, res);
}

void dfs(int cur, int s) {
    vis[cur] = s;
    int to = a[cur];
    if (vis[to] == s) ans += cost(to, cur, c[to]);
    if (!vis[to]) dfs(to, s);
}

int main() {
    cin.sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) dfs(i, i);
    }
    cout << ans;
    return 0;
}
