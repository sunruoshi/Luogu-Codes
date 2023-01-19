#include <iostream>
#include <vector>
using namespace std;

const int N = 5e4 + 1, INF = 0x3f3f3f3f;

int n, w[N], fa[N], siz[N], val[N], depth[N], zdson[N], cdson[N], cut, ans = INF;
vector<int> adj[N];

void dfs(int u, int pre) {
    siz[u] = w[u];
    fa[u] = pre;
    for (int v : adj[u]) {
        if (v == pre) continue;
        depth[v] = depth[u] + 1; // 根结点深度为 0
        dfs(v, u);
        siz[u] += siz[v];
        val[u] += val[v] + siz[v];
        if (siz[v] > siz[zdson[u]]) {
            cdson[u] = zdson[u];
            zdson[u] = v;
        } else if (siz[v] > siz[cdson[u]]) {
            cdson[u] = v;
        }
    }
}

void get(int u, int now, int all, int &res) {
    res = min(res, now);
    int v = zdson[u];
    if (v == cut || siz[cdson[u]] > siz[zdson[u]]) v = cdson[u];
    if (!v) return;
    if (siz[v] * 2 > all) get(v, now + all - 2 * siz[v], all, res);
}

void solve(int u) { // 自 1 向下枚举切断的边
    for (int v : adj[u]) {
        if (v == fa[u]) continue;
        // 切断 (u, v) 这条边
        cut = v;
        int A = INF, B = INF;
        for (int i = u; i; i = fa[i]) { // 重新计算 u 所在部分的大小
            siz[i] -= siz[v];
        }
        get(1, val[1] - val[v] - depth[v] * siz[v], siz[1], A);
        get(v, val[v], siz[v], B);
        ans = min(ans, A + B);
        for (int i = u; i; i = fa[i]) { // 回溯
            siz[i] += siz[v];
        }
        solve(v);
    }
}

int main() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        cin >> w[i];
    }
    dfs(1, 0);
    solve(1);
    cout << ans << endl;
    return 0;
}