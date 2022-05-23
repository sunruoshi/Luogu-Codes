#include <iostream>
using namespace std;

int main() {
    cin.sync_with_stdio(0);
    int n, q;
    cin >> n >> q;
    int rmax[n + 1][20], rmin[n + 1][20];
    for (int i = 1; i <= n; i++) {
        cin >> rmax[i][0];
        rmin[i][0] = rmax[i][0];
    }
    for (int j = 1; (1 << j) <= n; j++) {
        for (int i = 1; i + (1 << j) - 1 <= n; i++) {
            rmax[i][j] = max(rmax[i][j - 1], rmax[i + (1 << (j - 1))][j - 1]);
            rmin[i][j] = min(rmin[i][j - 1], rmin[i + (1 << (j - 1))][j - 1]);
        }
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        int k = 0;
        while ((1 << (k + 1)) <= r - l + 1) k++;
        int _max = max(rmax[l][k], rmax[r - (1 << k) + 1][k]);
        int _min = min(rmin[l][k], rmin[r - (1 << k) + 1][k]);
        cout << _max - _min << endl;
    }
    return 0;
}
