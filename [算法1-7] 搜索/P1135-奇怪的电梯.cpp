#include <iostream>
using namespace std;

int n, a, b, ans = 2147483647, arr[201], visited[201];

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
    cin >> n >> a >> b;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    dfs(a, 0);
    if (ans == 2147483647) cout << -1;
    else cout << ans;
    return 0;
}
