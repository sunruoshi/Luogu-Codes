#include <iostream>
using namespace std;

const int MAXN = 1000;

int n, m, g[MAXN + 1][MAXN + 1], d[MAXN + 2][MAXN + 2];

int main() {
    ios::sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for (int j = x1; j <= x2; j++) {
            d[j][y1]++;
            d[j][y2 + 1]--;
        }
    }
    for (int i = 1; i <= n; i++) {
        int sum = 0;
        for (int j = 1; j <= n; j++) {
            sum += d[i][j];
            g[i][j] = sum;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << g[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}
