#include <cstdio>
#include <cstring>

int main() {
    int i, n, sum;
    char num;
    char text[40000], str[200];
    scanf("%s", str);
    n = int(strlen(str));
    strcat(text, str);
    for (i = 2; i <= n; i++) {
        scanf("%s", str);
        strcat(text, str);
    }
    printf("%d ", n);
    for (i = 0, sum = 0, num = '0'; i <= strlen(text); i++)
        if (num == text[i])
            sum++;
        else {
            num = text[i];
            printf("%d ", sum);
            sum = 1;
        }
    return 0;
}
