#include <iostream>
#include <queue>
using namespace std;

struct Line {
    int l, r;
    bool operator < (const Line &a) const {
        return r > a.r;
    }
};

int main() {
    int n;
    cin >> n;
    priority_queue<Line> q;
    while (n--) {
        Line x;
        cin >> x.l >> x.r;
        q.push(x);
    }
    int cnt = 0, cur = 0;
    while (q.size()) {
        Line x = q.top();
        q.pop();
        if (x.l >= cur) {
            cnt++;
            cur = x.r;
        }
    }
    cout << cnt;
    return 0;
}
