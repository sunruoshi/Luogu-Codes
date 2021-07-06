#include <bits/stdc++.h>
using namespace std;

int main() {
    int q, n;
    cin >> q;
    while (q--) {
        stack<int> s;
        cin >> n;
        int pushed[n], poped[n], pos = 0;
        for (int i = 0; i < n; i++) {
            cin >> pushed[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> poped[i];
        }
        for (int i = 0; i < n; i++) {
            s.push(pushed[i]);
            while (s.top() == poped[pos]) {
                s.pop();
                pos++;
                if (s.empty()) break;
            }
        }
        string ans = s.empty() ? "Yes" : "No";
        cout << ans << endl;
    }
    return 0;
}
