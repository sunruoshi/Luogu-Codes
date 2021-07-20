#include <cstdio>
using namespace std;

const int MAXN = 201;

int n, a, b, ans = 1e9, arr[MAXN], visited[MAXN];

void dfs(int cur, int cnt) {
    if (cnt >= ans || cur == b) {
        if (cur == b && cnt < ans) ans = cnt;
        return;
    }
    visited[cur]++;
    if (cur + arr[cur] <= n && !visited[cur + arr[cur]]) dfs(cur + arr[cur], cnt + 1);
    if (cur - arr[cur] > 0 && !visited[cur - arr[cur]]) dfs(cur - arr[cur], cnt + 1);
    visited[cur]--;
}

int main() {
    scanf("%d %d %d", &n, &a, &b);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
    }
    dfs(a, 0);
    if (ans == 1e9) printf("-1");
    else printf("%d", ans);
    return 0;
}
