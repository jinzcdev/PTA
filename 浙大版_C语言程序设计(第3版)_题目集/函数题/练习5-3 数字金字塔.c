// https://pintia.cn/problem-sets/12/exam/problems/300
void pyramid( int n ) {
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < n - i; j++) printf(" ");
        for (int j = 0; j < i; j++) printf("%d ", i);
        printf("\n");
    }
}