#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

const int N = 1e5 + 1;

struct City {
    int h, pos, pre, nxt;
    bool operator < (const City &x) const {
        return h < x.h;
    }
} c[N];

int n, m, s, x, pos[N];
int nextA[N], nextB[N], d1[N], d2[N], nextAB[N][21], d[N][21], disA[N][21], disB[N][21];

inline void solve(int i, int x) {
    if (x < 1 || x > n) return;
    int dis = abs(c[pos[i]].h - c[x].h);
    if (!d1[i] || d1[i] > dis || (d1[i] == dis && c[x].h < c[pos[nextB[i]]].h)) {
        d2[i] = d1[i];
        d1[i] = dis;
        nextA[i] = nextB[i];
        nextB[i] = c[x].pos;
    } else if (!d2[i] || d2[i] > dis || (d2[i] == dis && c[x].h < c[pos[nextA[i]]].h)) {
        d2[i] = dis;
        nextA[i] = c[x].pos;
    }
}

void pre_processing() {
    for (int i = 1; i <= n; i++) {
        cin >> c[i].h;
        c[i].pos = i;
    }
    sort(c + 1, c + n + 1);
    for (int i = 1; i <= n; i++) {
        pos[c[i].pos] = i;
        if (i != 1) c[i].pre = i - 1;
        if (i != n) c[i].nxt = i + 1;
    }
    for (int i = 1; i <= n; i++) {
        solve(i, c[pos[i]].nxt);
        solve(i, c[pos[i]].pre);
        solve(i, c[c[pos[i]].pre].pre);
        solve(i, c[c[pos[i]].nxt].nxt);
        if (c[pos[i]].pre) c[c[pos[i]].pre].nxt = c[pos[i]].nxt;
        if (c[pos[i]].nxt) c[c[pos[i]].nxt].pre = c[pos[i]].pre;
        c[pos[i]].pre = c[pos[i]].nxt = 0;
    }
    for (int i = 1; i <= n; i++) {
        disA[i][0] = d2[i];
        disB[i][0] = d1[nextA[i]];
        d[i][0] = d2[i] + d1[nextA[i]];
        nextAB[i][0] = nextB[nextA[i]];
    }
    for (int j = 1; j <= 20; j++) {
        for (int i = 1; i <= n; i++) {
            nextAB[i][j] = nextAB[nextAB[i][j - 1]][j - 1];
            if (nextAB[i][j]) {
                d[i][j] = d[i][j - 1] + d[nextAB[i][j - 1]][j - 1];
                disA[i][j] = disA[i][j - 1] + disA[nextAB[i][j - 1]][j - 1];
                disB[i][j] = disB[i][j - 1] + disB[nextAB[i][j - 1]][j - 1];
            }
        }
    }
}

pair<int, int> getDist(int s, int x) {
    int suma = 0, sumb = 0;
    for (int j = 20; j >= 0; j--) {
        if (d[s][j] && x >= d[s][j]) {
            x -= d[s][j];
            suma += disA[s][j];
            sumb += disB[s][j];
            s = nextAB[s][j];
        }
    }
    if (d2[s] <= x) suma += d2[s];
    return make_pair(suma, sumb);
}

int main() {
    cin >> n;
    pre_processing();
    cin >> x >> m;
    double MIN = INT_MAX;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        pair<int, int> res = getDist(i, x); 
        double r = res.second ? 1.0 * res.first / res.second : INT_MAX;
        if (r < MIN) {
            MIN = r;
            ans = i;
        } else if (r == MIN && c[pos[i]].h > c[pos[ans]].h) {
            ans = i;
        }
    }
    cout << ans << endl;
    while (m--) {
        cin >> s >> x;
        pair<int, int> res = getDist(s, x);
        cout << res.first << ' ' << res.second << endl;
    }
    return 0;
}
