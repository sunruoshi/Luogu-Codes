#include <iostream>
#include <deque>
using namespace std;

const int MAXN = 1e6;

int n, k, a[MAXN];

int main() {
    ios::sync_with_stdio(0);
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    deque<int> q;
    for (int i = 0; i < n; i++) {
        while (q.size() && a[q.back()] >= a[i]) q.pop_back();
        q.push_back(i);
        while (q.front() <= i - k) q.pop_front();
        if (i >= k - 1) cout << a[q.front()] << ' ';
    }
    cout << endl;
    q.clear();
    for (int i = 0; i < n; i++) {
        while (q.size() && a[q.back()] <= a[i]) q.pop_back();
        q.push_back(i);
        while (q.front() <= i - k) q.pop_front();
        if (i >= k - 1) cout << a[q.front()] << ' ';
    }
    return 0;
}
