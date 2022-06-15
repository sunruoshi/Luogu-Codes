#include <iostream>
#include <cmath>
using namespace std;

const int N = 1e6 + 1;

int n, t, cnt[N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        t = max(t, x);
        int m = sqrt(x);
        for (int j = 1; j <= m; j++) {
            if (x % j) continue;
            cnt[j]++;
            if (x != j * j) cnt[x / j]++;
        }
    }
    int x = t;
    for (int i = 1; i <= n; i++) {
        while (cnt[x] < i) x--;
        cout << x << endl;
    }
    return 0;
}
