#include <iostream>
using namespace std;

const int N = 1e5 + 2;

int n, m, cur, pre, d[N];

int main() {
    cin.sync_with_stdio(0);
    cin >> n >> m;
    cin >> pre;
    for (int i = 2; i <= m; i++) {
        cin >> cur;
        if (pre < cur) {
            d[pre]++;
            d[cur]--;
        } else {
            d[cur]++;
            d[pre]--;
        }
        pre = cur;
    }
    long long sum = 0, ans = 0;
    for (int i = 1; i <= n - 1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        sum += d[i];
        if (sum) ans += min(a * sum, b * sum + c);
    }
    cout << ans << endl;
    return 0;
}
