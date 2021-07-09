#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, w;
    scanf("%d %d", &n, &w);
    vector<int> vec;
    for (int i = 1; i <= n; i++) {
        int d, cur = max(1, i * w / 100);
        scanf("%d", &d);
        vec.insert(lower_bound(vec.begin(), vec.end(), d), d);
        printf("%d ", vec[vec.size() - cur]);
    }
    return 0;
}
