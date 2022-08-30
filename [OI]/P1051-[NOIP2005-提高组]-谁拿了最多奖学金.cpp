#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int N = 101;

struct Stu {
    string name;
    int s1, s2, p, id, tot;
    char is_leader, from_west;
    bool operator < (const Stu &x) const {
        return tot == x.tot ? id < x.id : tot > x.tot;
    }
} s[N];

int n, sum;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s[i].name >> s[i].s1 >> s[i].s2 >> s[i].is_leader >> s[i].from_west >> s[i].p;
        s[i].id = i;
        if (s[i].s1 > 80 && s[i].p) s[i].tot += 8000;
        if (s[i].s1 > 85 && s[i].s2 > 80) s[i].tot += 4000;
        if (s[i].s1 > 90) s[i].tot += 2000;
        if (s[i].s1 > 85 && s[i].from_west == 'Y') s[i].tot += 1000;
        if (s[i].s2 > 80 && s[i].is_leader == 'Y') s[i].tot += 850;
        sum += s[i].tot;
    }
    sort(s, s + n);
    cout << s[0].name << endl << s[0].tot << endl << sum << endl;
    return 0;
}
