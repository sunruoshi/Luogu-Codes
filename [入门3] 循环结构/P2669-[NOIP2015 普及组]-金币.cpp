/*
 * 思路
 * 连续N天每天收到N枚金币为一个周期
 * 一个完整周期内共收到N * N枚金币
 * 从第一个周期（N = 1）开始遍历，到K天为止，算出共有多少个完整周期，累加到结果
 * 如果存在不完整的周期，再算出这部分金币并累加到结果
 */

# include <cstdio>

int main() {
    int K, N, coin = 0;
    scanf("%d", &K);
    for (N = 1; K >= N; K -= N++)
        coin += N * N;
    printf("%d\n", coin + K * N);
    return 0;
}
