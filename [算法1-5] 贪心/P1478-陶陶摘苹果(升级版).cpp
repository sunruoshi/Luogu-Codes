#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n, s, a, b;
    cin >> n >> s >> a >> b;
    priority_queue<int, vector<int>, greater<int>> q;
    while (n--) {
        int x, y;
        cin >> x >> y;
        if (x <= a + b) q.push(y);
    }
    int cnt = 0;
    while (q.size()) {
        if (s < q.top()) break;
        s -= q.top();
        q.pop();
        cnt++;
    }
    cout << cnt;
    return 0;
}
