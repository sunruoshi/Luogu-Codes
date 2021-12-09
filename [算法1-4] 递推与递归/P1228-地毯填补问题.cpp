#include <iostream>
using namespace std;

int k, x, y;

void solve(int x, int y, int a, int b, int len) {
    if (len == 1) return;
    int nx = a + (len >> 1), ny = b + (len >> 1);
    if (x <= nx - 1 && y <= ny - 1) {
        cout << nx << ' ' << ny << ' ' << 1 << endl;
        solve(x, y, a, b, len >> 1);
        solve(nx - 1, ny, a, ny, len >> 1);
        solve(nx, ny - 1, nx, b, len >> 1);
        solve(nx, ny, nx, ny, len >> 1);
    } else if (x <= nx - 1 && y > ny - 1) {
        cout << nx << ' ' << ny - 1 << ' ' << 2 << endl;
        solve(nx - 1, ny - 1, a, b, len >> 1);
        solve(x, y, a, ny, len >> 1);
        solve(nx, ny - 1, nx, b, len >> 1);
        solve(nx, ny, nx, ny, len >> 1);
    } else if (x > nx - 1 && y <= ny - 1) {
        cout << nx - 1 << ' ' << ny << ' ' << 3 << endl;
        solve(nx - 1, ny - 1, a, b, len >> 1);
        solve(nx - 1, ny, a, ny, len >> 1);
        solve(x, y, nx, b, len >> 1);
        solve(nx, ny, nx, ny, len >> 1);
    } else {
        cout << nx - 1 << ' ' << ny - 1 << ' ' << 4 << endl;
        solve(nx - 1, ny - 1, a, b, len >> 1);
        solve(nx - 1, ny, a, ny, len >> 1);
        solve(nx, ny - 1, nx, b, len >> 1);
        solve(x, y, nx, ny, len >> 1);
    }
}

int main() {
    cin >> k >> x >> y;
    solve(x, y, 1, 1, 1 << k);
    return 0;
}
