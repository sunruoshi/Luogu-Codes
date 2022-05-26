#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

const int MAXN = 1e5 + 1;

struct T {
    int st, ed;
    bool operator < (const T &x) const {
        return st < x.st;
    }
} a[MAXN], b[MAXN];

struct P {
    int leave_time, port_no;
    P(int x, int y) : leave_time(x), port_no(y) {}
    bool operator < (const P &x) const {
        return leave_time > x.leave_time;
    }
};

int n, m1, m2, ra[MAXN], rb[MAXN];

void solve(T* t, int m, int* res) {
    priority_queue<P, vector<P>> plane;
    priority_queue<int, vector<int>, greater<int>> port;
    for (int i = 1; i <= n; i++) {
        port.push(i);
    }
    for (int i = 1; i <= m; i++) {
        while (plane.size() && t[i].st >= plane.top().leave_time) {
            port.push(plane.top().port_no);
            plane.pop();
        }
        if (!port.size()) continue;
        int cur = port.top();
        port.pop();
        res[cur]++;
        plane.push(P(t[i].ed, cur));
    }
    for (int i = 1; i <= n; i++) {
        res[i] += res[i - 1];
    }
}

int main() {
    cin >> n >> m1 >> m2;
    for (int i = 1; i <= m1; i++) {
        cin >> a[i].st >> a[i].ed;
    }
    for (int i = 1; i <= m2; i++) {
        cin >> b[i].st >> b[i].ed;
    }
    sort(a + 1, a + m1 + 1);
    sort(b + 1, b + m2 + 1);
    solve(a, m1, ra);
    solve(b, m2, rb);
    int ans = 0;
    for (int i = 0; i <= n; i++) {
        ans = max(ans, ra[i] + rb[n - i]);
    }
    cout << ans << endl;
    return 0;
}
