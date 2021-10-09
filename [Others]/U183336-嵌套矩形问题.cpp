#include <cstdio>
#include <vector>
#include <algorithm>
#define MAXN 1001
using namespace std;

struct Rect {
    int a, b;
} rect[MAXN];

int n, ans, start, dp[MAXN], Next[MAXN];
vector<int> adj[MAXN];

int DP(int u) {
    if (dp[u]) return dp[u];
    for (int v : adj[u]) {
        int temp = DP(v);
        if (temp > dp[u]) {
            dp[u] = temp;
            Next[u] = v;
        }
    }
    dp[u] += 1;
    return dp[u];
}

int main() {
    auto check = [&](Rect x, Rect y) {
        return (x.a < y.a && x.b < y.b) || (x.b < y.a && x.a < y.b);
    };
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &rect[i].a, &rect[i].b);
    }
    for (int u = 1; u < n; u++) {
        for (int v = u + 1; v <= n; v++) {
            if (check(rect[u], rect[v])) adj[u].push_back(v);
            if (check(rect[v], rect[u])) adj[v].push_back(u);
        }
    }
    for (int i = 1; i <= n; i++) {
        dp[i] = DP(i);
        if (dp[i] > ans) {
            ans = dp[i];
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
