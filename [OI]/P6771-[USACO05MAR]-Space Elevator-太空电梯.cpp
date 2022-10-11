#include <iostream>
#include <algorithm>
using namespace std;

const int N = 401, H = 4e4 + 1;

struct Cube {
    int h, a, c;
    bool operator < (const Cube &x) const {
        return a < x.a;
    }
} a[N];

int n, dp[H];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].h >> a[i].a >> a[i].c;
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= a[i].c; j++) {
            for (int k = a[i].a; k >= a[i].h; k--) {
                dp[k] = max(dp[k], dp[k - a[i].h] + a[i].h);
            }
        }
    }
    cout << *max_element(dp + 1, dp + a[n].a + 1) << endl;
    return 0;
}
