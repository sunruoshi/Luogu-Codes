#include <cstdio>
#include <queue>
#define MAXN 100001
using namespace std;

queue<long long> q1, q2;
int freq[MAXN];

void read(int &x){ 
    int f = 1;
    x = 0;
    char s = getchar();
    while (s < '0'|| s > '9') {
        if (s == '-') f = -1;
        s = getchar();
    }
    while (s >= '0' && s <= '9') {
        x = x * 10 + s - '0';
        s = getchar();
    }
    x *= f;
}

int main() {
    int n;
    read(n);
    for (int i = 1; i <= n; i++) {
        int a;
        read(a);
        freq[a]++;
    }
    for (int i = 1; i < MAXN; i++) {
        while (freq[i]) {
            freq[i]--;
            q1.push(i);
        }
    }
    long long ans = 0;
    for (int i = 1; i < n; ++i) {
        long long x , y;
        if ((q1.front() < q2.front() && q1.size()) || !q2.size()) {
            x = q1.front();
            q1.pop();
        } else {
            x = q2.front();
            q2.pop();
        }
        if ((q1.front() < q2.front() && q1.size()) || !q2.size()) {
            y = q1.front();
            q1.pop();
        } else {
            y = q2.front();
            q2.pop();
        }
        ans += x + y;
        q2.push(x + y);
    } 
    printf("%lld" , ans);
    return 0;
} 
