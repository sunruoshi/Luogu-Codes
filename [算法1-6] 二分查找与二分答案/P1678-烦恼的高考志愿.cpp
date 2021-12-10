#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 100000;

int m, n, school[MAXN], student[MAXN];

int main() {
    ios::sync_with_stdio(0);
    cin >> m >> n;
    for (int i = 0; i < m; i++) {
        cin >> school[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> student[i];
    }
    sort(school, school + m);
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        int low = lower_bound(school, school + m, student[i]) - school;
        if (!low) ans += school[0] - student[i]; 
        else ans += min(abs(student[i] - school[low]), abs(student[i] - school[low - 1]));
    }
    cout << ans;
    return 0;
}
