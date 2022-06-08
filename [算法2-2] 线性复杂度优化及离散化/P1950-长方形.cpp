#include <iostream>
#include <stack>
using namespace std;

const int N = 1001;

int n, m, h[N][N], l[N], r[N];
char g[N][N];

int main() {
    cin.sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> g[i][j];    
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (g[i][j] == '.') h[i][j] = h[i - 1][j] + 1;
        }
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        stack<int> s;
        for (int j = 1; j <= m; j++) {
            while (s.size() && h[i][s.top()] >= h[i][j]) {
                r[s.top()] = j;
                s.pop();
            }
            s.push(j);
        }
        while (s.size()) {
            r[s.top()] = m + 1;
            s.pop();
        }
        for (int j = m; j >= 1; j--) {
            while (s.size() && h[i][s.top()] > h[i][j]) {
                l[s.top()] = j;
                s.pop();
            }
            s.push(j);
        }
        while (s.size()) {
            l[s.top()] = 0;
            s.pop();
        }
        for (int j = 1; j <= m; j++) {
            ans += (j - l[j]) * (r[j] - j) * h[i][j];
        }
    }
    cout << ans << endl;
    return 0;
}
