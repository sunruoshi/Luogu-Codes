#include <cstdio>
#include <vector>
using namespace std;

vector<bool> Eratosthenes(int n) {
    vector<bool> vis(n + 1);
    for (int i = 2; i * i <= n; i++) {
        if (vis[i]) continue;
        for (int j = i * i; j <= n; j += i) {
            vis[j] = 1;
        }
    }
    return vis;
}

int main() {
    int n;
    scanf("%d", &n);
    vector<bool> notPrime = Eratosthenes(n);
    for (int i = 2; i <= n; i++) {
        if (!notPrime[i]) printf("%d ", i);
    }
    return 0;
}
