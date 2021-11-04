#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 50000;

struct Cow {
    int vol, pos;
};

void update(size_t pos, long long val, long long *c) {
    while (pos <= MAXN) {
        c[pos] += val;
        pos += pos & (-pos);
    }
}

long long query(size_t pos, long long* c) {
    long long res = 0;
    while (pos) {
        res += c[pos];
        pos -= pos & (-pos);
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    Cow c[MAXN + 1];
    long long sum[MAXN + 1], cnt[MAXN + 1];
    memset(sum, 0, sizeof(sum));
    memset(cnt, 0, sizeof(cnt));
    for (int i = 1; i <= n; i++) {
        cin >> c[i].vol >> c[i].pos;
    }
    sort(c + 1, c + n + 1, [](Cow x, Cow y) { return x.vol < y.vol; });
    long long tot = 0, ans = 0;
    for (int i = 1; i <= n; i++) {
        long long cnt1 = query(c[i].pos, cnt), sum1 = query(c[i].pos, sum);
        long long cnt2 = i - 1 - cnt1, sum2 = tot - sum1;
        ans += c[i].vol * (cnt1 * c[i].pos - sum1 + sum2 - cnt2 * c[i].pos);
        tot += c[i].pos;
        update(c[i].pos, c[i].pos, sum);
        update(c[i].pos, 1, cnt);
    }
    cout << ans << endl;
    return 0;
}
