// https://pintia.cn/problem-sets/12/problems/357
void dectobin( int n ) {
    if (n <= 1) {
        printf("%d", n);
        return;
    }
    dectobin(n / 2);
    printf("%d", n % 2);
}