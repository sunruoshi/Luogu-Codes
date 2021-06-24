#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int ans, t = 1200, s[4];

void dfs(int cur, int left, int right, vector<int>& temp) {
    if (cur == temp.size()) {
        t = min(t, max(left, right));
        return;
    }
    left += temp[cur];
    dfs(cur + 1, left, right, temp);
    left -= temp[cur];
    right += temp[cur];
    dfs(cur + 1, left, right, temp);
}

int main() {
    for (int i = 0; i < 4; i++) {
        cin >> s[i];
    }
    for (int i = 0; i < 4; i++) {
        vector<int> temp (s[i]);
        t = 1200;
        for (int j = 0; j < s[i]; j++) {
            cin >> temp[j];
        }
        dfs(0, 0, 0, temp);
        ans += t;
    }
    cout << ans;
    return 0;
}
