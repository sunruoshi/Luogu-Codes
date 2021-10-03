#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 1;

int n, ans, nations[MAXN];

struct People {
    int time, nation;
};

int main() {
    scanf("%d", &n);
    deque<People> today;
    for (int i = 0; i < n; i++) {
        int t, k;
        scanf("%d %d", &t, &k);
        while (!today.empty() && t - today.front().time >= 86400) {
            nations[today.front().nation]--;
            if (nations[today.front().nation] == 0) ans--;
            today.pop_front();
        }
        for (int j = 0; j < k; j++) {
            People person;
            scanf("%d", &person.nation);
            person.time = t;
            nations[person.nation]++;
            if (nations[person.nation] == 1) ans++;
            today.push_back(person);
        }
        printf("%d\n", ans);
    }
    return 0;
}
