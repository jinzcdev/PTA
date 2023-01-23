// https://pintia.cn/problem-sets/14/problems/733
void PrintN(int N) {
    if (N == 0) return;
    PrintN(N - 1);
    printf("%d\n", N);
}

