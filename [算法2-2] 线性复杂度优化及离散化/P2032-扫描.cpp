#include <cstdio>
#include <deque>
using namespace std;

const int N = 2e6;

int n, k, a[N];

int main() {
    scanf("%d %d", &n, &k);
    deque<int> maxq;
    for (int i = 0; i < n; i++) {
        scanf("%d", a + i);
        while (maxq.size() && a[maxq.back()] <= a[i]) maxq.pop_back();
        maxq.push_back(i);
        while (maxq.front() <= i - k) maxq.pop_front();
        if (i - k + 1 >= 0) printf("%d\n", a[maxq.front()]);
    }
    return 0;
}
