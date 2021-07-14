#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5;

int n, cnt;
deque<int> arr[MAXN];

int binSearch(int x) {
    if (x > arr[cnt].front()) return ++cnt;
    int left = 0, right = cnt;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid].front() >= x) right = mid;
        else left = mid + 1;
    }
    return left;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        arr[binSearch(num)].push_front(num);
    }
    for (int i = 0; i <= cnt; i++) {
        deque<int>::iterator it;
        for (it = arr[i].begin(); it != arr[i].end(); it++) {
            printf("%d ", *it);
        }
        printf("\n");
    }
    printf("%d", cnt);
    return 0;
}
