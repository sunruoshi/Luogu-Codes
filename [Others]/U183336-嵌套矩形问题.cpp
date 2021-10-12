#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Rect {
    int a, b;
};

int DP(int u, int* dp, int* Next, vector<int>* adj) {
    if (dp[u]) return dp[u];
    for (int v : adj[u]) {
        int res = DP(v, dp, Next, adj);
        if (res > dp[u]) {
            dp[u] = res;
            Next[u] = v;
        } else if (res == dp[u] && to_string(v) < to_string(Next[u])) {
            Next[u] = v;
        }
    }
    dp[u] += 1;
    return dp[u];
}

int main() {
    int n;
    scanf("%d", &n);

    Rect rect[n + 1];
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &rect[i].a, &rect[i].b);
    }

    vector<int> adj[n + 1];
    auto check = [&](Rect x, Rect y) {
        return (x.a < y.a && x.b < y.b) || (x.b < y.a && x.a < y.b);
    };

    for (int u = 1; u < n; u++) {
        for (int v = u + 1; v <= n; v++) {
            if (check(rect[u], rect[v])) adj[u].push_back(v);
            if (check(rect[v], rect[u])) adj[v].push_back(u);
        }
    }

    int dp[n + 1], Next[n + 1], ans = 0, start = 0;
    memset(dp, 0, sizeof(dp));
    memset(Next, 0, sizeof(Next));

    for (int i = 1; i <= n; i++) {
        dp[i] = DP(i, dp, Next, adj);
        if (dp[i] > ans) {
            ans = dp[i];
            start = i;
        } else if (dp[i] == ans && to_string(i) < to_string(start)) {
            start = i;
        }
    }

    printf("%d\n", ans);
    while (start) {
        printf("%d ", start);
        start = Next[start];
    }
    return 0;
}
