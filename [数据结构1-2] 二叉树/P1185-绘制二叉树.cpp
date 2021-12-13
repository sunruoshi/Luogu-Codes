#include <iostream>
#include <cstring>
using namespace std;

int m, n, len;
char line[3 * (1 << 9)][6 * (1 << 9)];
bool del[(1 << 9) + 1][2];

void dfs(int y, int x, int p) {
    line[y][x]='o';
    if (y + 1 >= len >> 1) return;
    int t = (((len >> 1) - y) >> 1) + 1;
    if (!del[p][0]) {
        for (int i = 1; i < t; i++) {
            line[y + i][x - i] = '/';
        }
        dfs(y + t, x - t, p << 1);
    }
    if (!del[p][1]) {
        for(int i = 1; i < t; i++) {
            line[y + i][x + i] = '\\';
        }
        dfs(y + t, x + t, p << 1 | 1);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin >> m >> n;
    len = (1 << (m - 2)) * 6 - 1;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        del[((1 << (a - 2)) + ((b - 1) >> 1))][(b & 1) ^ 1] = 1;
    }
    memset(line, ' ', sizeof(line));
    dfs(0, len >> 1, 1);
    for (int i = 0; i <= len >> 1; i++) {
        line[i][len] = 0;
        cout << line[i] << endl;
    }
    return 0;
}
