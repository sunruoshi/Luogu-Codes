#include <iostream>
using namespace std;

int ans, t, s[4], temp[20];

void dfs(int cur, int left, int right, int len) {
    if (cur == len) {
        t = min(t, max(left, right));
        return;
    }
    left += temp[cur];
    dfs(cur + 1, left, right, len);
    left -= temp[cur];
    right += temp[cur];
    dfs(cur + 1, left, right, len);
}

int main() {
    for (int i = 0; i < 4; i++) {
        cin >> s[i];
    }
    for (int i = 0; i < 4; i++) {
        t = 1200;
        for (int j = 0; j < s[i]; j++) {
            cin >> temp[j];
        }
        dfs(0, 0, 0, s[i]);
        ans += t;
    }
    cout << ans;
    return 0;
}
