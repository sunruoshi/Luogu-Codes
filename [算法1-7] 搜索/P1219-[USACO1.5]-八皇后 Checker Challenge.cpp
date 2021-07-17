#include <bits/stdc++.h>
using namespace std;

int n, cnt, queen[13];

void dfs(int row, int col, int x1, int x2) {
    if (row == n) {
        cnt++;
        if (cnt <= 3) {
            for (int i = 0; i < n; i++) {
                cout << queen[i] << " ";
            }
            cout << endl;
        }
        return;
    }
    int pos = ((1 << n) - 1) & (~(col | x1 | x2));
    while (pos != 0) {
        int p = pos & (-pos);
        pos = pos & (pos - 1);
        // __builtin_ctz(x): 求x的二进制数末尾0的个数
        int column = __builtin_ctz(p) + 1;
        queen[row] = column;
        dfs(row + 1, col | p, (x1 | p) >> 1, (x2 | p) << 1);
        queen[row] = 0;
    }
}

int main() {
    cin >> n;
    dfs(0, 0, 0, 0);
    cout << cnt;
    return 0;
}
