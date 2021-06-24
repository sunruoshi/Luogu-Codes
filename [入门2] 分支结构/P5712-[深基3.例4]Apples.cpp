#include <cstdio>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    printf("Today, I ate %d %s.", n, n > 1 ? "apples" : "apple");
    return 0;
}
