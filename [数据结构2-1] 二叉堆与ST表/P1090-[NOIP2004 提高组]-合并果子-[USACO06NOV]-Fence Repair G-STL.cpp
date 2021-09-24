#include <cstdio>
#include <queue>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    priority_queue<int, vector<int>, greater<int>> q;
    while (n--) {
        int num;
        scanf("%d", &num);
        q.push(num);
    }
    int ans = 0;
    while (q.size() > 1) {
        int num1 = q.top();
        q.pop();
        int num2 = q.top();
        q.pop();
        ans += num1 + num2;
        q.push(num1 + num2);
    }
    printf("%d", ans);
    return 0;
}
