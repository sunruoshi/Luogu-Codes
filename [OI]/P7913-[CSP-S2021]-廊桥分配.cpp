#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

const int MAXN = 1e5 + 1;

struct T {
    int arrive_time, leave_time;
    bool operator < (const T &x) const {
        return arrive_time < x.arrive_time;
    }
} t1[MAXN], t2[MAXN];

struct P {
    int leave_time, port_no;
    P(int x, int y) : leave_time(x), port_no(y) {}
    bool operator < (const P &x) const {
        return leave_time > x.leave_time;
    }
};

int n, m1, m2, r1[MAXN], r2[MAXN];

void solve(T* t, int m, int* res) {
    priority_queue<P> plane;
    priority_queue<int, vector<int>, greater<int>> port;
    for (int i = 1; i <= n; i++) {
        port.push(i);
    }
    for (int i = 1; i <= m; i++) {
        while (plane.size() && t[i].arrive_time >= plane.top().leave_time) {
            port.push(plane.top().port_no);
            plane.pop();
        }
        if (!port.size()) continue;
        int cur = port.top();
        port.pop();
        res[cur]++;
        plane.push(P(t[i].leave_time, cur));
    }
    for (int i = 1; i <= n; i++) {
        res[i] += res[i - 1];
    }
}

int main() {
    cin >> n >> m1 >> m2;
    for (int i = 1; i <= m1; i++) {
        cin >> t1[i].arrive_time >> t1[i].leave_time;
    }
    for (int i = 1; i <= m2; i++) {
        cin >> t2[i].arrive_time >> t2[i].leave_time;
    }
    sort(t1 + 1, t1 + m1 + 1);
    sort(t2 + 1, t2 + m2 + 1);
    solve(t1, m1, r1);
    solve(t2, m2, r2);
    int ans = 0;
    for (int i = 0; i <= n; i++) {
        ans = max(ans, r1[i] + r2[n - i]);
    }
    cout << ans << endl;
    return 0;
}
