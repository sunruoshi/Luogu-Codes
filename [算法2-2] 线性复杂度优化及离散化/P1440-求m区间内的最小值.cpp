#include <cstdio>
#include <deque>
using namespace std;

const int N = 2e6;

int n, m, a[N];

int main() {
    scanf("%d %d", &n, &m);
    printf("0\n");
    deque<int> minq;
    for (int i = 0; i < n - 1; i++) {
        scanf("%d", a + i);
        while (minq.size() && a[minq.back()] >= a[i]) minq.pop_back();
        minq.push_back(i);
        while (minq.front() <= i - m) minq.pop_front();
        printf("%d\n", a[minq.front()]);
    }
    return 0;
}
