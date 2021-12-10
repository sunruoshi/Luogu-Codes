#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

struct P {
    long long L, R;
    bool operator < (const P &a) const {
        return L * R < a.L * a.R;
    }
} a[1001];

int n, p1 = 1, p2 = 1, p3 = 1;
int sum[10001] = {0, 1}, maxn[10001] = {0, 1}, ans[10001];

void mul(long long x) {
    int t = 0;
    for (int i = 1; i <= p1; i++) {
        sum[i] *= x;
    }
    for (int i = 1; i <= p1; i++) {
        t += sum[i];
        sum[i] = t % 10;
        t /= 10;
    }
    while (t) {
        sum[++p1] = t % 10;
        t /= 10;
    }
}

void div(long long x) {
    memset(ans, 0, sizeof(ans));
    p2 = p1;
    int t = 0;
    for (int i = p2; i >= 1; i--) {
        t *= 10;
        t += sum[i];
        if (t >= x) {
            ans[i] = t / x;
            t %= x;
        }
    }
    while (!ans[p2]) {
        if (p2 == 1) break;
        p2--;
    }
}

void getMax() {
    if (p2 > p3) {
        for (int i = 1; i <= p2; i++) {
            maxn[i] = ans[i];
        }
        p3 = p2;
    } else if (p2 == p3) {
        for (int i = p2; i >= 1; i--) {
            if (maxn[i] < ans[i]) {
                for (int j = 1; j <= p2; j++) {
                    maxn[j] = ans[j];
                }
                p3 = p2;
                break;
            }
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i <= n; i++) {
        cin >> a[i].L >> a[i].R;
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) {
        mul(a[i - 1].L);
        div(a[i].R);
        getMax();
    }
    for (int i = p3; i >= 1; i--) {
        cout << maxn[i];
    }
    return 0;
}
