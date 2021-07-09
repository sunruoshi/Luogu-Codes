#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1001;

int m, n, cnt, ram[MAXN];

int main() {
    deque<int> dict;
    scanf("%d %d", &m, &n);
    for (int i = 0; i < n; i++) {
        int word;
        scanf("%d", &word);
        if (!ram[word]) {
            if (dict.size() == m) {
                ram[dict.front()] = 0;
                dict.pop_front();
            }
            ram[word] = 1;
            dict.push_back(word);
            cnt++;
        }
    }
    printf("%d", cnt);
    return 0;
}
