#include <iostream>
using namespace std;

const int MAXN = 5e4 + 1;

int n, q, h[MAXN], rmax[MAXN][20], rmin[MAXN][20];

int query_max(int l, int r) {
    int k = 0;
    while ((1 << (k + 1)) <= r - l + 1) k++;
    return max(rmax[l][k], rmax[r - (1 << k) + 1][k]);
}

int query_min(int l, int r) {
    int k = 0;
    while ((1 << (k + 1)) <= r - l + 1) k++;
    return min(rmin[l][k], rmin[r - (1 << k) + 1][k]);
}

int main() {
    cin.sync_with_stdio(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }
    for (int i = 1; i <= n; i++) {
        rmax[i][0] = rmin[i][0] = h[i];
    }
    for (int j = 1; (1 << j) < n; j++) {
        for (int i = 1; i + (1 << j) - 1 <= n; i++) {
            rmax[i][j] = max(rmax[i][j - 1], rmax[i + (1 << (j - 1))][j - 1]);
            rmin[i][j] = min(rmin[i][j - 1], rmin[i + (1 << (j - 1))][j - 1]);
        }
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << query_max(l, r) - query_min(l, r) << endl;
    }
    return 0;
}
