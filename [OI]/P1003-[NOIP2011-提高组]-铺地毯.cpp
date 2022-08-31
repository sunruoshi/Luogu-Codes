#include <iostream>
using namespace std;

struct C {
    int a, b, g, k;
} c[10001];

int n, x, y;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> c[i].a >> c[i].b >> c[i].g >> c[i].k;
    }
    cin >> x >> y;
    for (int i = n; i >= 1; i--) {
        if (x >= c[i].a && x <= c[i].a + c[i].g && y >= c[i].b && y <= c[i].b + c[i].k) {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}
