#include <iostream>
using namespace std;

int n, cnt, queen[13], col[14], x1[27], x2[27];

void dfs(int row) {
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
    for (int i = 1; i <= n; i++) {
        if (col[i] || x1[row - i + n] || x2[row + i]) continue;
        queen[row] = i;
        col[i]++;
        x1[row - i + n]++;
        x2[row + i]++;
        dfs(row + 1);
        x2[row + i]--;
        x1[row - i + n]--;
        col[i]--;
        queen[row] = 0;
    }
}

int main() {
    cin >> n;
    dfs(0);
    cout << cnt;
    return 0;
}
