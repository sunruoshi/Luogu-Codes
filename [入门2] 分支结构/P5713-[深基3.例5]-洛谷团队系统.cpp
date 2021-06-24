#include <cstdio>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    printf("%s", n * 5 < 11 + n * 3 ? "Local" : "Luogu");
    return 0;
}
