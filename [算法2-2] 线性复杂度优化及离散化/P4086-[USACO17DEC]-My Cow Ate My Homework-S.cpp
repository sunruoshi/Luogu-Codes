#include <iostream>
#include <deque>
using namespace std;

const int N = 1e5 + 1;

int n, a[N], s[N];
double high[N];
deque<int> minq;

int main() {
    cin.sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }
    double max_score = 0;
    minq.push_back(n);
    for (int i = n - 1; i >= 2; i--) {
        while (minq.size() && a[minq.back()] >= a[i]) minq.pop_back();
        minq.push_back(i);
        high[i - 1] = 1.0 * (s[n] - s[i - 1] - a[minq.front()]) / (n - i);
        max_score = max(max_score, high[i - 1]);
    }
    for (int i = 1; i <= n - 2; i++) {
        if (high[i] == max_score) cout << i << endl;
    }
    return 0;
}
