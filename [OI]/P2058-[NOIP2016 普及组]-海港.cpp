#include <cstdio>
#include <queue>
#define MAXN 100001
using namespace std;

int n, ans, nations[MAXN];

struct People {
    int time, nation;
};

int main() {
    scanf("%d", &n);
    queue<People> today;
    for (int i = 0; i < n; i++) {
        int t, k;
        scanf("%d %d", &t, &k);
        while (today.size() && t - today.front().time >= 86400) {
            nations[today.front().nation]--;
            if (nations[today.front().nation] == 0) ans--;
            today.pop();
        }
        for (int j = 0; j < k; j++) {
            People person;
            scanf("%d", &person.nation);
            person.time = t;
            nations[person.nation]++;
            if (nations[person.nation] == 1) ans++;
            today.push(person);
        }
        printf("%d\n", ans);
    }
    return 0;
}
